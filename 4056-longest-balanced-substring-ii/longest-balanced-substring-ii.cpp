#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length(), maxLen = 0;

        // 1. Single character case
        int run = 0;
        for (int i = 0; i < n; i++) {
            run = (i > 0 && s[i] == s[i-1]) ? run + 1 : 1;
            maxLen = max(maxLen, run);
        }

        // 2. Substrings with exactly TWO distinct characters
        auto solve2 = [&](char c1, char c2) {
            unordered_map<int, int> seen;
            seen[0] = -1;
            int diff = 0, last1 = -1, last2 = -1, lastOther = -1;
            
            for (int i = 0; i < n; i++) {
                if (s[i] == c1) { diff++; last1 = i; }
                else if (s[i] == c2) { diff--; last2 = i; }
                else {
                    // This character is not part of our pair. 
                    // To ensure the substring only has c1 and c2 as DISTINCT chars,
                    // we must "cut" the window here.
                    seen.clear();
                    diff = 0;
                    seen[0] = i;
                    last1 = last2 = -1;
                    continue;
                }

                if (seen.count(diff)) {
                    int prev = seen[diff];
                    // Must contain BOTH characters to have 2 distinct chars
                    if (last1 > prev && last2 > prev) {
                        maxLen = max(maxLen, i - prev);
                    }
                } else {
                    seen[diff] = i;
                }
            }
        };

        solve2('a', 'b');
        solve2('a', 'c');
        solve2('b', 'c');

        // 3. Substrings with exactly THREE distinct characters
        unordered_map<long long, int> seen3;
        seen3.reserve(n);
        seen3[0] = -1;
        int ca = 0, cb = 0, cc = 0, la = -1, lb = -1, lc = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') { ca++; la = i; }
            else if (s[i] == 'b') { cb++; lb = i; }
            else { cc++; lc = i; }

            long long key = ((long long)(ca - cb) << 32) | (unsigned int)(cb - cc);
            if (seen3.count(key)) {
                int p = seen3[key];
                if (la > p && lb > p && lc > p) maxLen = max(maxLen, i - p);
            } else seen3[key] = i;
        }

        return maxLen;
    }
};