class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        int cur_max = -1;
        for (int i = 0; i < n; i++) {
            cur_max = max(cur_max, jobDifficulty[i]);
            dp[i][0] = cur_max;
        }
        if (d == 1) {
            return dp[n - 1][0];
        }

        for (int days = 1; days <= d - 1; days++) {
            for (int last_ending = days - 1; last_ending <= n - 2; last_ending++) {
                int cur_max_tail = -1;
                for (int cur_ending = last_ending + 1; cur_ending < n; cur_ending++) {
                    cur_max_tail = max(cur_max_tail, jobDifficulty[cur_ending]);
                    dp[cur_ending][days] =  min(
                            dp[cur_ending][days],
                            dp[last_ending][days - 1] + cur_max_tail
                            );
                }
            }
        }
        return dp[n - 1][d - 1];
    }
};
