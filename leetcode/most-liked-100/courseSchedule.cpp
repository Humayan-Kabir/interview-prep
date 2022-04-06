class Solution {
public:
    vector<int> color;
    vector<int> adj;
    bool isCycleFound = false;
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
       color[u] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        color = vector<int>(numCourses);
        adj = vector<vector<int>>(numCourses, vector<int>());
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        for(int i = 0; i < numCourses; i++) {
            if (color[i] == 0 && !isCycleFound) {
                dfs(i);
            }
        }
        return isCycleFound;
    }
};

