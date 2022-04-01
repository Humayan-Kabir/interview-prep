class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        map<pair<int,int>, int> visited;
        queue<pair<int,int>> q;
        q.push({0, 0});
        visited[{0, 0}] = 0;
        int n = grid.size();
        int m = grid[0].size();
        if (n + m - 2 <= k) {
            return n + m - 2;
        }
        int dist = 0;
        while(!q.empty()) {
            dist++;
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                int u = it.first;
                int v = it.second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int x = u + dx[i];
                    int y = v + dy[i];
                    if (x == n - 1 && y == m - 1) {
                        return dist;
                    }
                    if (x >= 0 && x < n && y >= 0 && y < m) {
                        if (visited.find({x, y}) == visited.end() || visited[{x, y}] > visited[{u, v}] + grid[x][y]) {
                             if (visited[{u, v}] + grid[x][y] <= k) {
                                  visited[{x, y}] = visited[{u, v}] + grid[x][y];
                                  q.push({x, y});
                             }
                        }              
                    }
                }
            }
        }
        return -1;
    }
};