class Solution {
public:
    unordered_map<int, int> hashMap;
    int rec(int num) {
        if (hashMap.find(num) == hashMap.end()) {
            return 0;
        }
        if (hashMap[num] != 0) {
            return hashMap[num];
        }
        return hashMap[num] = 1 + rec(num + 1);
    }
    int longestConsecutive(vector<int>& nums) {
        for(int element: nums) {
            hashMap[element] = 0;
        }
        int maxLength = 0;
        for(int element: nums) {
            maxLength = max(maxLength, rec(element));
        }
    }
};
