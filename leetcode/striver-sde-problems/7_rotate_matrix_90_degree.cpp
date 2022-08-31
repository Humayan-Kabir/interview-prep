class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reflect(matrix);      
    }
    void transpose(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
    void reflect(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n / 2; j++) {
                swap(mat[i][j], mat[i][n - 1 - j]);
            }
        }
    }
};