class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counter(26, 0);
        for(char ch : s) {
            counter[ch]++;
        }
        for(char ch : t) {
            counter[ch]--;
        }
        for(int i = 0; i < 26; i++) {
            if (counter[i] != 0) {
                return false;
            }
        }
        return true;
    }
};