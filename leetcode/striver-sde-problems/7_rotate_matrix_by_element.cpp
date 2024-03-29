void rotateMatrix(vector<vector<int>> &mat, int n, int m) {
    for(int i = 1; i <= min(n, m) / 2; i++) {
        int x = i - 1;
        int y = i - 1;
        int prev = mat[x][y];
        while(y + i < m) swap(prev, mat[x][++y]);
        while(x + i < n) swap(prev, mat[++x][y]);
        while(y >= i) swap(prev, mat[x][--y]);
        while(x >= i) swap(prev, mat[--x][y]);
    }
}