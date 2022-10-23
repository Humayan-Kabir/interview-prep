class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;
        for(int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int j = i + 1, k = nums.size() - 1;
                while(j < k) {
                    int total = nums[i] + nums[j] + nums[k];
                    if (total < 0) {
                        j++;
                    } else if (total > 0) {
                        k--;
                    } else {
                        triplets.push_back({nums[i], nums[j], nums[k]});
                        while(j + 1 < nums.size() && nums[j + 1] == nums[j]) {
                            j++;
                        }
                        j++;
                    }
                }
            }
        }
        return triplets;      
    }
};