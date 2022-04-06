class Solution {
public:
    bool rec(int x, int y, int matched, vector<vector<char>> &board, string &word) {
        if (matched == word.size()) {
            return true;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '#') {
            return false;
        }
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        bool isPossible = false;
        for(int i = 0; i < 4 && !isPossible; i++) {
            if (word[matched] == board[x][y]) {
                board[x][y] = '#';
                isPossible |= rec(x + dx[i], y + dy[i], matched + 1, board, word);
                board[x][y] = word[matched];
            } 
        }
        return isPossible;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool isPossible = false;
        for(int i = 0; i < board.size() && !isPossible; i++) {
            for(int j = 0; j < board[0].size() && !isPossible; j++) {
                isPossible |= rec(i, j, 0, board, word);
            }
        }
        return isPossible;
    }
};
