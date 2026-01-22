#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int operations = 0;

        // Continue until the array is sorted in non-decreasing order
        // std::is_sorted returns true for empty or single-element arrays
        while (!std::is_sorted(nums.begin(), nums.end())) {
            int minSum = INT_MAX;
            int targetIdx = -1;

            // 1. Find the adjacent pair with the minimum sum
            // We use '<' to ensure we pick the leftmost pair in case of a tie
            for (int i = 0; i + 1 < nums.size(); ++i) {
                long long currentSum = (long long)nums[i] + nums[i+1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    targetIdx = i;
                }
            }

            // 2. Replace the pair with their sum
            // Update the element at targetIdx and remove the element at targetIdx + 1
            nums[targetIdx] = minSum;
            nums.erase(nums.begin() + targetIdx + 1);

            operations++;
        }

        return operations;
    }
};