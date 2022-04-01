class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &l, vector<int> &r) {return l[0] < r[0];});
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for(auto it : intervals) {
            if (it[0] <= prev[1]) {
                prev[1] = max(prev[1], it[1]);
            } else {
                ans.push_back(prev);
                prev = it;
            }
        }
        ans.push_back(prev);
        return ans;        
    }
};
