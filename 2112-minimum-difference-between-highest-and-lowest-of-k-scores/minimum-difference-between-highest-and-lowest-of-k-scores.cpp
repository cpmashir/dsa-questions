class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // If we only need to pick one student, the difference is always 0
        if (k == 1) return 0;

        // Step 1: Sort the scores
        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        // Step 2: Slide a window of size k across the sorted array
        // The window starts at i and ends at i + k - 1
        for (int i = 0; i <= nums.size() - k; ++i) {
            int currentDiff = nums[i + k - 1] - nums[i];
            minDiff = min(minDiff, currentDiff);
        }

        return minDiff;
    }
};