class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int ans = 0, diff = INT_MAX;
		for(int i = 0; i < nums.size(); i++) {
			int low = i + 1, high = nums.size() - 1;
			while(low < high) {
				int currentSum = nums[i] + nums[low] + nums[high];
				if (diff > abs(target - currentSum)) {
					diff = abs(target - currentSum);
					ans = currentSum;
				}
				if (currentSum < target) {
					low++;
				} else {
					high--;
				}
			}
		}
		return ans;      
    }
};  
