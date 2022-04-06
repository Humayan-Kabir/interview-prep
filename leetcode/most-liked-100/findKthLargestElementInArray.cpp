class Solution {
public:
    int findKth(int left, int right, vector<int>& nums, int k) {
        int pivot = left + random() % (right - left + 1);
        int storeAt = left;
        swap(nums[pivot], nums[right]);
        for(int i = left; i <= right; i++) {
            if (nums[i] < nums[right]) {  
                swap(nums[storeAt++], nums[i]);
            }
        }
        swap(nums[storeAt], nums[right]);
        if (storeAt < k) {
            return findKth(storeAt + 1, right, nums, k);
        } else if (storeAt > k) {
            return findKth(left, storeAt - 1, nums, k); 
        } 
        return nums[storeAt];
    }
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(0, nums.size() - 1, nums, nums.size() - k);       
    }
};
