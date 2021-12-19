class Solution {
public:
    string findHash(string str) {
        string result = "";
        vector<int> counter(26, 0);
        for(char ch : str) {
            counter[ch - 'a']++;
        }
        for(int cnt : counter) {
            result += string(cnt) + "#";
        }
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> maping;
        for(string str: strs) {
            maping[findHash(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it : maping) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
