class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int ans = 0;

        for (int c1 = 0; c1 < m; c1++) {
            for (int c2 = c1; c2 < m; c2++) {
                int pref_sum = 0;
                unordered_map<int, int> counter;
                counter[0] = 1;

                for (int row = 0; row < n; row++) {
                    int row_subsum = matrix[row][c2] - (
                            c1 > 0 ? matrix[row][c1 - 1] : 0
                            );
                    pref_sum += row_subsum;

                    if (counter.find(pref_sum - target) != counter.end()) {
                        ans += counter[pref_sum - target];
                    }

                    counter[pref_sum]++;
                }
            }
        }
        return ans;
    }
};
