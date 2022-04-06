class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int x = 0, y = cols - 1;
        while(x < rows && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                x++;
            } else {
                y--;
            }
        }
        return false;       
    }
};
