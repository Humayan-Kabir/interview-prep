class Solution {
public:
    int maxSubArray(vector<int>& nums) {
  		int ans = INT_MIN;
  		int curSum = 0;
  		for(int i = 0; i < nums.size(); i++) {
  			curSum += nums[i];
  			ans = max(ans, curSum);
  			if (curSum < 0) {
  				curSum = 0;
  			}
  		}
  		return ans;      
    }
};