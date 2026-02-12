class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> count(26, 0);
            int distinctChars = 0;

            for (int j = i; j < n; ++j) {
                int charIdx = s[j] - 'a';
                if (count[charIdx] == 0) {
                    distinctChars++;
                }
                count[charIdx]++;

                if (isBalanced(count)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }

private:
    bool isBalanced(const vector<int>& count) {
        int commonFreq = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0) {
                if (commonFreq == -1) {
                    commonFreq = count[i];
                } else if (count[i] != commonFreq) {
                    return false;
                }
            }
        }
        return true;
    }
};