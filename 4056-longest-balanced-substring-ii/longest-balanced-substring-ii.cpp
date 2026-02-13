#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int maxLen = 0;
        vector<string> combos = {"a", "b", "c", "ab", "ac", "bc", "abc"};
        for (const string& combo : combos) {
            maxLen = max(maxLen, solve(s, combo));
        }
        return maxLen;
    }

private:
    int solve(const string& s, const string& target) {
        unordered_map<long long, int> firstSeen;
        firstSeen[0] = -1;
        
        int counts[3] = {0, 0, 0};
        int localMax = 0;
        int lastInvalid = -1;
        
        // Track how many unique target characters we've seen in the current segment
        int distinctSeen = 0;
        int lastSeenIdx[3] = {-1, -1, -1};

        for (int i = 0; i < s.length(); ++i) {
            int charIdx = s[i] - 'a';
            
            if (target.find(s[i]) == string::npos) {
                firstSeen.clear();
                firstSeen[0] = i;
                counts[0] = counts[1] = counts[2] = 0;
                lastInvalid = i;
                continue;
            }

            counts[charIdx]++;
            lastSeenIdx[charIdx] = i;

            long long state = 0;
            if (target.length() == 1) {
                state = 0; 
            } else if (target.length() == 2) {
                if (target == "ab") state = counts[0] - counts[1];
                else if (target == "ac") state = counts[0] - counts[2];
                else state = counts[1] - counts[2];
            } else {
                // Encode two differences into a single long long for the hash map
                state = ((long long)(counts[0] - counts[1]) << 32) | (unsigned int)(counts[1] - counts[2]);
            }

            if (firstSeen.count(state)) {
                int startIdx = firstSeen[state];
                // Check if ALL target characters have appeared since startIdx
                bool allPresent = true;
                for (char c : target) {
                    if (lastSeenIdx[c - 'a'] <= startIdx) {
                        allPresent = false;
                        break;
                    }
                }
                if (allPresent) {
                    localMax = max(localMax, i - startIdx);
                }
            } else {
                firstSeen[state] = i;
            }
        }
        return localMax;
    }
};