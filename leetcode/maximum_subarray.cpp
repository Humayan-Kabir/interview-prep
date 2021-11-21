class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int result = INT_MIN;
	int sum = 0;
	for(int num: nums) {
		sum += num;
		result = max(result, sum);
		if(sum < 0) {
			sum = 0;
		}
	}
	return result;	
    }
};
