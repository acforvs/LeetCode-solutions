class Solution {
public:
    string longestDupSubstring(string s) {
        const int p = 31;
        vector<uint64_t> p_pow(s.length());
        p_pow[0] = 1;
        for (int i = 1; i < p_pow.size(); i++) {
            p_pow[i] = p * p_pow[i - 1];
        }

        int n = s.length();
        int left = 0, right = n - 1;
        int cur_pos = -1;
        int cur_len = -1;

        while (left <= right) {
            bool ok = false;
            int l = left + (right - left) / 2;
            unordered_map<uint64_t, int> seen;
            uint64_t h_l = 0;

            for (int i = 0; i < l; i++) {
                h_l += (s[i] - 'a' + 1) * p_pow[l - i - 1];
            }

            seen[h_l] = 0;

            for (int i = 1; i < n - l + 1; i++) {
                h_l *= p;
                h_l -= (s[i - 1] - 'a' + 1) * p_pow[l];
                h_l += (s[i + l - 1] - 'a' + 1);

                if (seen.find(h_l) != seen.end()) {
                    cur_pos = i;
                    cur_len = l;
                    ok = true;
                    break;
                } else {
                    seen[h_l] = i;
                }
            }
            if (ok) {
                left = l + 1;
                continue;
            } else {
                right = l - 1;
            }
        }
        assert(cur_pos != -1);
        assert(cur_len != -1);
        return s.substr(cur_pos, cur_len);
    }
};
