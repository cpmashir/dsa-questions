#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // Step 1: Sort the array. Time: O(N log N)
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> result;
        int min_diff = INT_MAX;
        
        // Step 2: Single pass to find the minimum difference and collect pairs
        for (int i = 0; i < arr.size() - 1; ++i) {
            int current_diff = arr[i + 1] - arr[i];
            
            if (current_diff < min_diff) {
                // Found a new global minimum; clear previous results
                min_diff = current_diff;
                result.clear();
                result.push_back({arr[i], arr[i + 1]});
            } 
            else if (current_diff == min_diff) {
                // Found another pair with the same minimum difference
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        
        return result;
    }
};