class Solution {
public:
    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};
    void dfs(int x, int y, vector<vector<char>> &grid) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0') {
            return; //out of the grid or water
        }
        grid[x][y] = '0';
        for(int i = 0; i < 4; i++) {
            dfs(x + dx[i], y + dy[i], grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};


