class Solution {
public:
    bool isPallindrome(string &s, int start, int end) {
        while(start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++; end--;
        }
        return true;
    }
    void backTrack(string &s, int curpos, vector<vector<string>> &ans, vector<string> &partition) {
        if (curpos == s.length()) {
            ans.push_back(partition);
            return;
        }
        for(int i = curpos; i < s.length(); i++) {
            if (isPallindrome(s, curpos, i)) {
                partition.emplace_back(s.substr(i, curpos - i + 1));
                backTrack(s, i + 1, ans, partition);
                partition.pop_back();
            }
        } 
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        return backTrack(s, 0, ans, partition);
    }
};

