class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int total = 1 << k;
        int ones = total - 1;
        int hash = 0;

        vector<bool> got(total, false);
        for (int i = 0; i < n; i++) {
            hash = ((hash << 1) & ones) | (s[i] - '0');
            if (i >= k - 1 && !got[hash]) {
                got[hash] = true;
                total--;
                if (total == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};
