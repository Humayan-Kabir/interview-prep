3class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> countS;
        unordered_map<char,int> countT;
        for(char ch : t) {
            countT[ch]++;
        }
        int minLen = INT_MAX;
        int left = 0;
        int matched = 0;
        int need = countT.size();
        int substrStart = 0;
        for(int i = 0; i < s.length(); i++) {
            countS[s[i]]++;
            if(countS[s[i]] == countT[s[i]]) {
                matched++;
            }
            if (matched == need) {
                while(left < i && countS[s[left]] > countT[s[left]]) {
                    if (countS[s[left]] == countT[s[left]]) {
                        matched--;
                    }
                    countS[s[left]]--;
                    left++;
                }
                int currentLen = i - left + 1;
                if (minLen > currentLen) {
                    minLen = currentLen;
                    substrStart = left;
                }
            }
        }   
        return (minLen == INT_MAX) ? "" : s.substr(substrStart, minLen);
    }
};