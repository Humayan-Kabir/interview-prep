#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> maping;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (maping.find(target - num) != maping.end()) {
                ans.push_back(maping[target - num]);
                ans.push_back(i);
                break;
            } else {
                maping[num] = i;
            }
        }
        return ans;
    }
};