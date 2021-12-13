class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if (n == 0 || m == 0) return n + m;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int d1 = dp[i - 1][j];
                int d2 = dp[i][j - 1];
                int d3 = dp[i - 1][j - 1] - 1;
                if (word1[i - 1] != word2[j - 1]) {
                    d3 += 1;
                }
                dp[i][j] = 1 + min(d1, min(d2, d3));
            }
        }
        return dp[n][m];
    }
};
