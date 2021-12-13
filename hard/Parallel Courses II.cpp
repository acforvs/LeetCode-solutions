class Solution {
    vector<int> dp;
    int n, k;
    vector<vector<int>> g;
public:
    int minNumberOfSemesters(int N, vector<vector<int>>& relations, int K) {
        n = N; k = K;
        g.resize(n);
        dp.assign(1 << n, -1);
        for (auto &relation : relations) {
            g[relation[0] - 1].push_back(relation[1] - 1);
        }
        return count(0);
    }
private:
    int count(int mask) {
        if (mask == (1 << n) - 1) {
            return 0;
        }
        if (dp[mask] != -1) {
            return dp[mask];
        }

        vector<int> degree(n, 0);
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                continue;
            }
            for (auto &to : g[i]) {
                degree[to]++;
            }
        }
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0 && !(mask & (1 << i))) {
                tmp |= (1 << i);
            }
        }
        int ans = n + 1;

        int taken = __builtin_popcount(tmp);
        if (taken <= k) {
            ans = min(ans, 1 + count(mask | tmp));
        }
        else {
            for (int j = tmp; j; j = (j - 1)&tmp) {
                int cnt = __builtin_popcount(j);
                if (cnt != k) continue;
                ans = min(ans, 1 + count(mask | j));
            }
        }
        return dp[mask] = ans;
    }
};
