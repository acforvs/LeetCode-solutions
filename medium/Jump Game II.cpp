class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            int jump_len = nums[i];
            dp[i] = INT_MAX - 1;
            for (int j = i + 1; j <= i + jump_len; j++) {
                if (j >= n) break;
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[0];
    }
};
