class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &left, vector<int> &right) {return left[1] < right[1]});
        int cnt = 0, lastEnd = INT_MIN;
        for(auto it : intervals) {
            if (it[0] > lastEnd) {
                cnt++;
                lastEnd = it[1];
            }
        }
        return intervals.size() - cnt;       
    }
};
