class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        vector<int> counter(256, 0);
        for(int i = 0; i < s.length(); i++) {
            counter[s[i]]++;
            while(left < i && counter[s[i]] >= 2) {
                counter[s[left]]--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;      
    }
};