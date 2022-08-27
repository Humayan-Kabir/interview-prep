class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		int firstRowCnt = 0;
		int firstColumnCnt = 0;
		for(int j = 0; j < m; j++) firstRowCnt += matrix[0][j] == 0;
		for(int i = 0; i < n; i++) firstColumnCnt += matrix[i][0] == 0;
    	for(int i = 1; i < n; i++) {
    		for(int j = 1; j < m; j++) {
    			if (matrix[i][j] == 0) {
    				matrix[i][0] = 0;
    				matrix[0][j] = 0;
    			}
    		}
    	}
    	for(int i = 1; i < n; i++) {
    		for(int j = 1; j < m; j++) {
    			if(matrix[i][0] == 0 || matrix[0][j] == 0) {
    				matrix[i][j] = 0;
    			}
    		}
    	}
    	for(int j = 0; j < m && firstRowCnt > 0; j++) matrix[0][j] = 0;
    	for(int i = 0; i < n && firstColumnCnt > 0; i++) matrix[i][0] = 0;
    }
};