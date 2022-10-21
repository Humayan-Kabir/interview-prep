class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> hashMap;
        for(int num : nums) {
            hashMap[num] = true;
        }
        int ans = 0;
        for(int num : nums) {
            if (hashMap.find(num - 1) == hashMap.end()) {
                int chain = 0;
                while(hashMap.find(num) != hashMap.end()) {
                    chain++; 
                    num++;
                }
                ans = max(ans, chain);
            }
        }
        return ans;
    }
};