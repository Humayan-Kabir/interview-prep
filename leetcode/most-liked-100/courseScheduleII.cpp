class Solution {
public:
    vector<int> color;
    vector<vector<int>> adj;
    bool isCycleFound = false;
    vector<int> ans;
    void dfs(int u) {
        if (isCycleFound) {
            return;
        }
        color[u] = 1;
        for(int v : adj[u]) {
            if (color[v] == 0) {
                dfs(v);
            } else if(color[v] == 1) {
                isCycleFound = true;
            }
        }
       ans.push_back(u);
       color[u] = 2;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        color = vector<int>(numCourses);
        adj = vector<vector<int>>(numCourses, vector<int>());
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        for(int i = 0; i < numCourses; i++) {
            if (color[i] == 0 && !isCycleFound) {
                dfs(i);
            }
        }
        if (!isCycleFound) {
            reverse(ans.begin(), ans.end());
            return ans;
        } else {
            return {};
        }
    }
};


