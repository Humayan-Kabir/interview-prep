class Solution {
public:
    int romanToInt(string s) {
        map<string, int> hashMap;
        hashMap["I"] = 1;
        hashMap["IV"] = 4;
        hashMap["V"] = 5;
        hashMap["IX"] = 9;
        hashMap["X"] = 10;
        hashMap["XL"] = 40;
        hashMap["L"] = 50;
        hashMap["XC"] = 90;
        hashMap["C"] = 100;
        hashMap["CD"] = 400;
        hashMap["D"] = 500;
        hashMap["CM"] = 900;
        hashMap["M"] = 1000;
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && hashMap.find(s.substr(i, 2)) != hashMap.end()) {
                ans += hashMap[s.substr(i, 2)];
                i++;
            } else {
                ans += hashMap[s.substr(i, 1)];
            }
        }
        return ans;
    }
};