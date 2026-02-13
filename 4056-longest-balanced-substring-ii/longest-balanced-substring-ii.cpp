#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        // We check every possible set of characters that could be 'distinct' in a substring
        // There are 7 combinations: {a}, {b}, {c}, {ab}, {ac}, {bc}, {abc}
        vector<string> combos = {"a", "b", "c", "ab", "ac", "bc", "abc"};

        for (const string& combo : combos) {
            // Using a simple array-based hash for 2-char combos or a map for 3-char
            maxLen = max(maxLen, solve(s, combo));
        }

        return maxLen;
    }

private:
    int solve(const string& s, const string& target) {
        // Use a hash map to store the first time a specific 'difference state' is seen
        // We use a long long to pack (countA-countB) and (countB-countC)
        unordered_map<long long, int> firstSeen;
        firstSeen[0] = -1; // Base case: all counts are 0 at index -1

        int counts[3] = {0, 0, 0};
        int lastSeen[3] = {-1, -1, -1};
        int localMax = 0;

        for (int i = 0; i < s.length(); ++i) {
            int cur = s[i] - 'a';
            
            // If character is not in our target set, reset the state
            if (target.find(s[i]) == string::npos) {
                firstSeen.clear();
                firstSeen[0] = i;
                counts[0] = counts[1] = counts[2] = 0;
                continue;
            }

            counts[cur]++;
            lastSeen[cur] = i;

            // Generate a unique key based on the differences
            long long key = 0;
            if (target.length() == 1) {
                key = 0; // Any sequence of one char is balanced
            } else if (target.length() == 2) {
                // Get the two chars in the combo
                int c1 = target[0] - 'a';
                int c2 = target[1] - 'a';
                key = counts[c1] - counts[c2];
            } else {
                // For abc, we need two differences: (a-b) and (b-c)
                long long diff1 = counts[0] - counts[1];
                long long diff2 = counts[1] - counts[2];
                key = (diff1 << 32) | (diff2 & 0xFFFFFFFFLL);
            }

            if (firstSeen.count(key)) {
                int prevIdx = firstSeen[key];
                // CRITICAL: Substring is only valid if ALL target characters 
                // have appeared at least once since the prevIdx
                bool valid = true;
                for (char c : target) {
                    if (lastSeen[c - 'a'] <= prevIdx) {
                        valid = false;
                        break;
                    }
                }
                if (valid) localMax = max(localMax, i - prevIdx);
            } else {
                firstSeen[key] = i;
            }
        }
        return localMax;
    }
};