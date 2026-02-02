class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> last_seen;
        
        for (int i = 0; i < nums.size(); i++) {
        
            if (last_seen.find(nums[i]) != last_seen.end()) {
            
                if (i - last_seen[nums[i]] <= k) {
                    return true;
                }
            }
        
            last_seen[nums[i]] = i;
        }
        
        return false;
    }
};