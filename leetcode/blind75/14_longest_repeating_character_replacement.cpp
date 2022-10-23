class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int left = 0;
        int mxCnt = 0;
        vector<int> counter(26, 0);
        for(int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'A';
            counter[idx]++;
            mxCnt = max(mxCnt, counter[idx]);
            int needToReplace = i - left + 1 - mxCnt;
            if (needToReplace > k) {
                counter[s[left] - 'A']--;
                left++;
            } else {
                ans = max(ans, i - left + 1);
            }
        }
        return ans;      
    }
};