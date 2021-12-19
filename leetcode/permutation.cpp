class Solution {
public:
    static int MAX_N = 6;
    bool taken[MAX_N];
    void rec(int pos, vector<int> &nums, vector<int> &currentOrder, vector<vector<int>> &permutations) {
        if (pos == nums.size()) {
            permutations.push_back(currentOrder);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if (!taken[i]) {
                taken[i] = true;
                currentOrder.push_back(nums[i]);
                rec(pos + 1, nums, currentOrder, permutations);
                taken[i] = false;
                currentOrder.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> current;
       rec(0, nums, current, ans);
       return ans;
    }
};
