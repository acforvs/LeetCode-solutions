class Solution {
public:
    long double ans = 0.0;
    int stop_after;

    void dfs(
            int v,
            long double prob,
            int target,
            int time,
            vector<vector<int>>& graph,
            vector<long double> &ins,
            vector<bool> &used
            ) {
        used[v] = true;
        for (auto &to : graph[v]) {
            if (time + 1 <= stop_after && !used[to])
                dfs(
                        to,
                        (long double) prob / (ins[v] - (v != 0)),
                        target,
                        time + 1,
                        graph,
                        ins,
                        used);
        }
        if (v == target && ins[v] - (v != 0) == 0 && time < stop_after) {
            ans += prob;
        }

        if (v == target && time == stop_after) {
            ans += prob;
        }
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<bool> used(n, 0);
        vector<vector<int>> graph(n);
        vector<long double> ins(n, 0);
        for (auto &edge : edges) {
            int from = edge[0], to = edge[1];
            from--; to--;
            graph[from].push_back(to);
            graph[to].push_back(from);
            ins[from]++;
            ins[to]++;
        }
        stop_after = t;
        dfs(0, 1.0, target - 1, 0, graph, ins, used);
        return ans;
    }
};
