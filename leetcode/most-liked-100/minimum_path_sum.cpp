class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j == 0) continue;
                int upResult = i > 0 ? grid[i - 1][j] : 1e9;
                int leftResult = j > 0 ? grid[i][j - 1] : 1e9;
                grid[i][j] = min(upResult + grid[i][j], leftResult + grid[i][j]);             
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];       
    }
};
