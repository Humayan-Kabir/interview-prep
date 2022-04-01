class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> closest;
        for(int i = 0; i < points.size(); i++) {
            closest.push(points[i]);
            if (closest.size() > k) {
                closest.pop();
            }
        }
        vector<vector<int>> ans;
        while(!closest.empty()) {
            ans.push_back(closest.top());
            closest.pop();
        }        
        return ans;
    }
    struct Comparator {
      bool operator() (const vector<int> &lhs, const vector<int> &rhs) {
          int distLeft = lhs[0] * lhs[0] + lhs[1] * lhs[1];
          int distRight = rhs[0] * rhs[0] + rhs[1] * rhs[1];
          if (distLeft != distRight) {
            return distLeft < distRight;
          } else {
            return lhs[0] < rhs[0];
          }
      }  
    };
};
