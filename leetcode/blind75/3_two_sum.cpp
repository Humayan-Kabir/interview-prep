class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (hashMap.find(need) != hashMap.end()) {
                return {hashMap[need], i};
            }
            hashMap[nums[i]] = i;
        }
        return {};    
    }
};