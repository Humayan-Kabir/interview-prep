class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        for(int i = 0; i < nums.size(); i++) {
            nums[abs(nums[i])] *= -1;
            if (nums[abs(nums[i])] > 0) {
                ans = nums[i];
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = abs(nums[i]);
        }
        return ans;       
    }
};
