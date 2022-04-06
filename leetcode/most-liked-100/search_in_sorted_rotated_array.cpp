class Solution {
public:
    int binarySearchElement(vector<int> &nums, int target, int low, int high) {
        int ans = -1;
        if (target < nums[low] || target > nums[high]) return ans;
        while(low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int secondSegmentStart = nums.size();
        while(low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[0]) {
                secondSegmentStart = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int ans1 = binarySearchElement(nums, target, 0, secondSegmentStart - 1);
        int ans2 = binarySearchElement(nums, target, secondSegmentStart, nums.size() - 1);
        return max(ans1, ans2);
    }
};
