class Solution {
public:
    string decodeString(string s) {
        stack<string> stkStr;
        stack<int> stkCnt;
        string word = "";
        int number = 0, len = s.length();
        for(int i = 0; i < len;) {
            if (s[i] == '[') {
                stkCnt.push(number);
                stkStr.push(word);
                number = 0; word = ""; i++;
                continue;   
            }
            if (s[i] == ']') {
                string now = stkStr.top();
                int cnt = stkCnt.top();
                stkStr.pop();
                stkCnt.pop();
                while(cnt--) {
                    now += word;
                }
                word = now; i++;
                continue;
            }
            while(i < len && isalpha(s[i])) {
                word += s[i];
                i++;
            }
            while(i < len && isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
                i++;
            }
            
        }
        return word;       
    }
};
