class Solution {
public:
    static const int MAX_NUM = 30;
    static const int MAX_TARGET = 501;
    int dp[MAX_NUM][MAX_TARGET];
    bool rec(int pos, int value, vector<int> &nums, int target) {
        if (pos == nums.size()) {
            return value == target;
        }
        int &ret = dp[pos][value];
        if (ret != -1) {
            return ret;
        }
        int status = 0;
        if (value + nums[pos] <= target) {
           status |= rec(pos, value + nums[pos], nums, target);
        }
        status |= rec(pos + 1, value, nums, target);
        return ret = status;
    }
    void printSolution(int pos, int value, vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> temp) {
        if (pos == nums.size()) {
            ans.push_back(temp);
            return;
        }
        if (value + nums[pos] <= target && rec(pos, value + nums[pos], nums, target)) {
            temp.push_back(nums[pos]);
            printSolution(pos, value + nums[pos], nums, target);
        }
        if (rec(pos + 1, value, nums, target)) {
            printSolution(pos + 1, value, nums, target);
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        memset(dp, -1, sizeof dp);
        rec(0, 0, nums, target);
        vector<vector<int>> ans;
        vector<int> vt;
        return printSolution(0, 0, nums, target, ans, vt);
    }
};
