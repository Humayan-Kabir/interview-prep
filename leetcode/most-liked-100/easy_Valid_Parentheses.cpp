#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> stk;
		for(char ch: s) {
			if (ch == '(' || ch == '{' || ch == '[') {
				stk.push(ch);
			} else {
				switch(ch) {
					case ')':
						ch = '(';
						break;
					case '}':
						ch = '{';
						break;
					case ']':
						ch = '[';
						break;
					default:
						puts("input format not ok");
				}
				if (!stk.empty() && stk.top() == ch) {
					stk.pop();
				} else {
					return false;
				}
			}	
		}
		return stk.empty();	
    }
};
