class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      for (int i = 0; i < nums.size(); i++) {
          int idx = abs(nums[i]) - 1;
          if (nums[idx] > 0) {
            nums[idx] *= -1;
          }
      }
      vector<int> ans;
      for (int i = 1; i <= n; i++) {
        if (nums[i] > 0) {
            ans.push_back(i);
        }
      }
      return ans;
    }
};
