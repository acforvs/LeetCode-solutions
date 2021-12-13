class Solution {
public:
    bool validateCntVector(vector<int>& cnt) {
        for (int i = 0; i < 9; i++) {
            if (cnt[i] > 1) return false;
        }
        return true;
    }

    bool validateRow(vector<vector<char>>& board, int i) {
        vector<int> cnt(9, 0);
        for (int j = 0; j < 9; j++) {
            int digit = board[i][j];
            if ('1' <= digit && digit <= '9') {
                cnt[digit - 1 - '0']++;
            }
        }
        return validateCntVector(cnt);
    }

    bool validateColumn(vector<vector<char>>& board, int j) {
        vector<int> cnt(9, 0);
        for (int i = 0; i < 9; i++) {
            int digit = board[i][j];
            if ('1' <= digit && digit <= '9') {
                cnt[digit - 1 - '0']++;
            }
        }
        return validateCntVector(cnt);
    }

    bool validateBox(vector<vector<char>>& board, int i, int j) {
        vector<int> cnt(9, 0);
        for (int c = 0; c < 3; c++) {
            for (int r = 0; r < 3; r++) {
                int digit = board[3 * i + c][3 * j + r];
                if ('1' <= digit && digit <= '9') cnt[digit - 1 - '0']++;
            }
        }
        return validateCntVector(cnt);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            bool ok = validateRow(board, i) && validateColumn(board, i);
            if (!ok) return false;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                bool ok = validateBox(board, i, j);
                if (!ok) return false;
            }
        }
        return true;
    }
};
