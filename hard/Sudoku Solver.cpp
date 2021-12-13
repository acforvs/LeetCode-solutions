class Solution {
public:
    bool check_board(vector<vector<char>>& board, int i, int j, char digit) {
        for (int c = 0; c < 9; c++) {
            if (board[c][j] == digit) return false;
        }
        for (int r = 0; r < 9; r++) {
            if (board[i][r] == digit) return false;
        }
        int q_x = i / 3;
        int q_y = j / 3;
        for (int c = 0; c < 3; c++) {
            for (int r = 0; r < 3; r++) {
                if (board[q_x * 3 + c][q_y * 3 + r] != digit) continue;
                return false;
            }
        }
        return true;
    }
        
    bool solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;
                for (char digit = '1'; digit <= '9'; digit++) {
                    if (check_board(board, i, j, digit)) {
                        board[i][j] = digit;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
};
