class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int temp = 1;
        for(int i = 0; i < nums.size() - 1; i++) {
            temp *= nums[i];
            result[i + 1] *= temp;
        }
        temp = 1;
        for(int i = nums.size() - 1; i > 0; i--) {
            temp *= nums[i];
            result[i - 1] *= temp;
        }
        return result;      
    }
};