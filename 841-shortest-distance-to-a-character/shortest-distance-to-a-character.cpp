#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> answer(n);
        
        // Initialize with a value larger than any possible distance
        int last_seen = -10001; 

        // Forward Pass: Distance to the nearest 'c' on the left
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                last_seen = i;
            }
            answer[i] = i - last_seen;
        }

        // Backward Pass: Distance to the nearest 'c' on the right
        // Reset last_seen to a value far outside the right boundary
        last_seen = 20001; 
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) {
                last_seen = i;
            }
            // We take the minimum of the existing distance and the new distance
            answer[i] = min(answer[i], last_seen - i);
        }

        return answer;
    }
};