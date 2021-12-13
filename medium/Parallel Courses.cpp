class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> degree(n + 1, 0);
        vector<vector<int>> g(n + 1);
        for (auto &relation: relations) {
            g[relation[0]].push_back(relation[1]);
            degree[relation[1]]++;
        }
        
        vector<int> q;
        for (int i = 1; i < n + 1; i++) {
            if (degree[i] == 0) {
                q.push_back(i);
            }
        }
        int steps = 0;
        int cnt = 0;

        while (!q.empty()) {
            steps++;
            vector<int> nxt;
            for (auto &v : q) {
                cnt++;
                for (auto &to : g[v]) {
                    degree[to]--;
                    if (degree[to] == 0) {
                        nxt.push_back(to);
                    }
                }
            }
            q = nxt;
        }
        if (cnt != n) return -1;
        return steps;
    }
};
