#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minimumPairRemoval(std::vector<int>& nums) {
        int operations = 0;

        while (!std::is_sorted(nums.begin(), nums.end())) {
            int minSum = INT_MAX;
            int targetIdx = -1;

            for (int i = 0; i + 1 < nums.size(); ++i) {
                long long currentSum = (long long)nums[i] + nums[i+1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    targetIdx = i;
                }
            }

            nums[targetIdx] = minSum;
            nums.erase(nums.begin() + targetIdx + 1);

            operations++;
        }

        return operations;
    }
};