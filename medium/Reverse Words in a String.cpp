class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int l = 0, r = 0;
        
        while (r < n) {
            if (s[r] == ' ') {
                r++;
                if (1 <= l && s[l - 1] != ' ' && r < n) {
                    s[l++] = ' ';
                }
            } else {
                s[l++] = s[r++];
            }
        }
        s.resize(l);
        if (s.back() == ' ') {
            s.pop_back();
        }
        n = s.length();
        
        l = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                reverse(s, l, i - 1);
                l = i + 1;
            }
        }
        reverse(s, l, n - 1);
        reverse(s, 0, n - 1);
        return s;
        
    }
    
    void reverse(string &s, int l, int r) {
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};
