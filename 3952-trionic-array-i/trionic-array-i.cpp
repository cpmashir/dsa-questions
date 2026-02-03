class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 0;

        // Phase 1: Strictly Increasing (Up to peak p)
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        
        // If i didn't move, or we reached the end, it's not trionic
        if (i == 0 || i == n - 1) return false;
        
        // Phase 2: Strictly Decreasing (Down to valley q)
        int p = i; // Current peak
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }
        
        // If i didn't move past the peak, or we reached the end
        if (i == p || i == n - 1) return false;
        
        // Phase 3: Strictly Increasing (Up to the end)
        int q = i; // Current valley
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        
        // If we reached the last index, the array is trionic
        return i == n - 1;
    }
};