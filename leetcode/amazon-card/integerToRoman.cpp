class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> costArr = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"}
            {1000, "M"}
        }; 
        string ans = "";
        for(int i = costArr.size() - 1; i >= 0; i--) {
            while (costArr[i].first <= num) {
                ans += costArr[i].second;
                num -= costArrr[i].first;
            }
        }
        return ans;
    }
};
