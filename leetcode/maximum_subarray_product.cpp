class Solution {
public:
    int maxProduct(vector<int>& nums) {
  	int ans = INT_MIN;
  	int product = 1;
  	int fistNegative = 1;
  	
  	for(int i = 0; i < nums.size(); i++) {
  		if (!nums[i]) {
  			if (firstNegative < 0) {
  				ans = max(ans, product/firstNegative);
  				firstNegative = 1;
  			}
  			ans = max(ans, 0);
  			product = 1;
  		} else {
  			product *= nums[i];	
  			ans = max(ans, product);
  			if (nums[i] < 0 && firstNegative == 1) {
  				firstNegative = nums[i];
  			}  			
  		}
  	}
    }
};
