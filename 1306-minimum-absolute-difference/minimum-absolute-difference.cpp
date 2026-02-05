#include <vector>
#include <algorithm>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int min_diff = arr[1] - arr[0];
        
        for (int i = 2; i < n; ++i) {
            if (arr[i] - arr[i-1] < min_diff) {
                min_diff = arr[i] - arr[i-1];
            }
        }
        
        vector<vector<int>> result;
        for (int i = 1; i < n; ++i) {
            if (arr[i] - arr[i-1] == min_diff) {
                result.push_back({arr[i-1], arr[i]});
            }
        }
        
        return result;
    }
};