#include<bits/stdc++.h>
using namespace std;

int longestSubStringWithKDistinct(string str, int k) {
    unordered_map<char,int> hashMap;
    int ans = 0;
    int windowStart = 0;
    for(int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
        char ch = str[windowEnd];
        hashMap[ch]++;
        while(hashMap.size() > k) {
            int oldChar = str[windowStart++];
            auto it = hashMap.find(oldChar);
            if(it->second == 1) {
                hashMap.erase(it);
            } else {
                hashMap[oldChar]--;
            }
        }
        ans = max(ans, windowEnd - windowStart + 1);
    }
    return ans;
}

int main() {
    cout << longestSubStringWithKDistinct("araaci", 1) << endl;
}