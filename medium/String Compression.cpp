class Solution {
public:
    int compress(vector<char>& a) {
        if (a.size() == 1) return 1;
        if (a.size() == 0) return 0;
        int l = 0, n = a.size();
        int i = 1;
        for (i = 1; i < n; i++) {
            int cnt = 1;
            while (i < n && a[i] == a[i - 1]) {
                cnt++;
                i++;
            }
            a[l] = a[i - 1]; l++;
            if (cnt == 1) continue;
            string str_cnt = to_string(cnt);
            for (auto ch : str_cnt) {
                a[l] = ch;
                l++;
            }
        }

        if (i == n && a[i - 1] != a[i - 2]) {
            a[l] = a[i - 1];
            l++;
        }
        return l;
    }
};
