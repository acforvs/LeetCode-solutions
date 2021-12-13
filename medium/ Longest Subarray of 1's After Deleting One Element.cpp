class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == nums.size()) {
            return nums.size() - 1;
        }
        if (sum == 0) {
            return 0;
        }

        int cnt_0 = 0;
        int cnt_1 = 0;
        vector<pair<int, int>> seq;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (cnt_0 != 0) {
                    seq.push_back({0, cnt_0});
                    cnt_0 = 0;
                }
                cnt_1++;
            }
            if (nums[i] == 0) {
                if (cnt_1 != 0) {
                    seq.push_back({1, cnt_1});
                    cnt_1 = 0;
                }
                cnt_0++;
            }
        }
        if (cnt_0 != 0) {
            seq.push_back({0, cnt_0});
        }
        if (cnt_1 != 0) {
            seq.push_back({1, cnt_1});
        }

        for (int i = 0; i < seq.size(); i++) {
            auto d = seq[i];
            cout << d.first << "*" << d.second << ' ';
        }
        cout << endl;
        int cand = 0;
        for (int i = 0; i < seq.size(); i++) {
            auto d = seq[i];
            if (d.first == 1) {
                cand = max(cand, d.second);
            }
        }

        int ans = 0;
        for (int i = 0; i < seq.size(); i++) {
            auto d = seq[i];
            if (d.first == 0 && d.second == 1) {
                int s = 0;
                if (i > 0) {
                    s += seq[i - 1].second;
                }
                if (i < seq.size() - 1) {
                    s += seq[i + 1].second;
                }
                ans = max(ans, s);
            }
        }
        return max(ans, cand);
    }
};
