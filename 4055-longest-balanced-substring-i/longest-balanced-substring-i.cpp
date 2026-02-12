class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        for (int numDistinct = 1; numDistinct <= 26; ++numDistinct) {
            for (int freq = 1; freq * numDistinct <= n; ++freq) {
                int windowSize = numDistinct * freq;
                vector<int> count(26, 0);
                int distinctInWindow = 0;
                int countWithFreq = 0;

                for (int i = 0; i < n; ++i) {
                    // Add new character
                    int addIdx = s[i] - 'a';
                    if (count[addIdx] == 0) distinctInWindow++;
                    count[addIdx]++;
                    if (count[addIdx] == freq) countWithFreq++;
                    else if (count[addIdx] == freq + 1) countWithFreq--;

                    // Remove character sliding out
                    if (i >= windowSize) {
                        int remIdx = s[i - windowSize] - 'a';
                        if (count[remIdx] == freq) countWithFreq--;
                        count[remIdx]--;
                        if (count[remIdx] == freq) countWithFreq++;
                        if (count[remIdx] == 0) distinctInWindow--;
                    }

                    // Check if current window is balanced
                    if (distinctInWindow == numDistinct && countWithFreq == numDistinct) {
                        maxLen = max(maxLen, windowSize);
                    }
                }
            }
        }
        return maxLen;
    }
};