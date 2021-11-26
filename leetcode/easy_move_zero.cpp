class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPointer = 0, nonZeroPointer = 0, len = nums.size();
        while(zeroPointer < len && nonZeroPointer < len) {
            while(zeroPointer < len && nums[zeroPointer]) {
                zeroPointer++;
            }
            nonZeroPointer = zeroPointer;
            while(nonZeroPointer < len && !nums[nonZeroPointer]) {
                nonZeroPointer++;
            }
            if (zeroPointer < len && nonZeroPointer < len) {
                swap(nums[zeroPointer], nums[nonZeroPointer]);
            }
        }
    }
};
