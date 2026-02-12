class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            int counts[26] = {0};
            int distinct = 0;
            int maxFreq = 0;

            for (int j = i; j < n; ++j) {
                int idx = s[j] - 'a';
                if (counts[idx] == 0) {
                    distinct++;
                }
                counts[idx]++;
                
                // Track the frequency of the current character
                // A balanced string must have: length == distinct * current_frequency
                int currentFreq = counts[idx];
                int length = j - i + 1;

                if (length == distinct * currentFreq) {
                    bool balanced = true;
                    for (int k = 0; k < 26; ++k) {
                        if (counts[k] > 0 && counts[k] != currentFreq) {
                            balanced = false;
                            break;
                        }
                    }
                    if (balanced) {
                        maxLen = max(maxLen, length);
                    }
                }
            }
        }
        return maxLen;
    }
};