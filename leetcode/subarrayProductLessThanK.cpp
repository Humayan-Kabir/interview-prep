class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int rightPointer = 0;
        int product =  1;
        for(int i = 0; i < nums.size(); i++) {
            if (i > 0) {
                product /= nums[i - 1];
            }
            while(rightPointer < nums.size() && product * nums[rightPointer] < k) {
                rightPointer++;
            }
            ans += max(0, rightPointer - i + 1);
        }
    }
};
