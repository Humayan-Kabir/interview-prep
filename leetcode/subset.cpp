class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < (1 << len); i++) {
            vector<int> subset;
            for(int j = 0; j < len; j++) {
                if (i & (1 << j)) {
                    subset.emplace_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }       
        return ans;
    }
};
