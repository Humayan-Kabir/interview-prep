class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> maping;
        int sum = 0, ans = 0;
        maping[0] = 1;
        for(int num : nums) {
            sum = (sum + num) % k;
            ans += (maping[sum]);
            maping[sum] += 1;
        }       
    }
};
