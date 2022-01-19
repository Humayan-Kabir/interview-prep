class Solution {
public:
    bool rec(int startPos, string &s, vector<bool> &dp, unordered_map<string, bool> &hashMap) {
        if (startPos >= s.length()) {
            return 1;
        }
        if (dp[startPos] != -1) {
            return dp[startPos];
        }
        int isPossible = 0;
        string str = "";
        while(startPos < s.length()) {
            str += s[startPos];
            if (hashMap.find(str) != hashMap.end()) {
                isPossible |= rec(startPos + 1, s, dp, hashMap);
            }
        }
        return dp[startPos] = isPossible;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length(), -1);
        unordered_map<string, bool> hashMap;
        for(string word: wordDict) {
            hashMap[word] = true;
        }
        return rec(0, s, dp, hashMap);     
    }
};
