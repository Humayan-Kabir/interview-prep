class Solution {
public:
    int findMin(vector<int>& nums) {
        int pivot = 0;
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= nums[0]) {
                low = mid + 1;
                pivot = mid;
            } else {
                high = mid - 1;
            }
        }
        return (pivot == nums.size() - 1) ? nums[0] : nums[pivot + 1];      
    }
};