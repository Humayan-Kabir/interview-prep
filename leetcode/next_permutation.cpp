class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool found = false;
        for(int i = nums.size() - 1; i > 1; i--) {
            if (nums[i - 1] < nums[i]) {
                found = true;
                int smallestAmongGreaterPos = i;
                for(int j = i; j < nums.size(); j++) {
                    if (nums[j] > nums[i - 1]) {
                        smallestAmongGreaterPos = j;
                    }
                }
                swap(nums[i - 1], nums[smallestAmongGreaterPos]);
                reverse(nums.begin() + i, nums.end());
            }
        }
        if (!found) {
            reverse(nums.begin(), nums.end());
        }        
    }
};
