class Solution {
private:
    string getCntHash(string &str) {
        int cnt[26] = {0};
        for(char ch : str) {
            cnt[ch - 'a']++;
        }
        string hash = "";
        for(int i = 0; i < 26; i++) {
            hash += "#";
            hash += to_string(cnt[i]);
        }
        return hash;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> hashMap;
        int idx = 0;
        for(string str : strs) {
            string hash = getCntHash(str);
            if (hashMap.find(hash) == hashMap.end()) {
                hashMap[hash] = idx++;
                ans.push_back({});
            }
            int id = hashMap[hash];
            ans[id].push_back(str);
        }
        return ans;
    }
};