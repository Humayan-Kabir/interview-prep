class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = -1, end = -1;
        for(int i = 0; i < intervals.size(); i++) {
            int b = intervals[i][0];
            int e = intervals[i][1];
            if (b > end) {
                if (i > 0) {
                    ans.push_back({start, end});
                }
                start = b;
            }
            end = max(end, e); 
        }
        ans.push_back({start, end}); 
        return ans;      
    }
};
