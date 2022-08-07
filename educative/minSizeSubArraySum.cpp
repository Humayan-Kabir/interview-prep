#include<bits/stdc++.h>
using namespace std;

int findMinSizeSubArray(vector<int> vt, int target) {
    int minLength = INT_MAX;
    int windowSum = 0;
    int windowStart = 0;
    for(int windowEnd = 0; windowEnd < vt.size(); windowEnd++) {
        windowSum += vt[windowEnd];
        while(windowSum >= target) {
            minLength = min(minLength, windowEnd - windowStart + 1);
            windowSum -= vt[windowStart++];
        }
    }
    return minLength < INT_MAX ? minLength : 0;
}

int main() {
    cout << findMinSizeSubArray({2, 1, 5, 2, 3, 2}, 72) << endl;
    return 0;
}