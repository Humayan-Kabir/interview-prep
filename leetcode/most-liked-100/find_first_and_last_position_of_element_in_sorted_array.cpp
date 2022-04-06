class Solution {
public:
    int lower_bound(vector<int> &nums, int target) {
        int ans = -1;
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) {
                    ans = mid;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int upper_bound(vector<int> &nums, int target) {
        int ans = -1;
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) {
                    ans = mid;
                }
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lower_bound(nums, target), upper_bound(nums, target)};
    }
};
