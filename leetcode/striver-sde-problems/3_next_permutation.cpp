class Solution {
public:
    void nextPermutation(vector<int>& nums) {
  		bool isFound = false;
  		for(int i = nums.size() - 1; i > 0 && !isFound; i--) {
  			if (nums[i] > nums[i - 1]) {
  				for(int j = nums.size() - 1; j >= i; j--) {
  					if (nums[j] > nums[i - 1]) {
  						swap(nums[i - 1], nums[j]);
  						break;
  					}
  				}
  				reverse(nums.begin() + i, nums.end());
  				isFound = true;
  			}
  		}
  		if (!isFound) {
  			reverse(nums.begin(), nums.end());
  		}      
  		return nums;
    }
};