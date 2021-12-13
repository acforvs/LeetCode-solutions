class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) return s;
        int ians = -1, jans = -1;
        for (int i = 0; i < n; i++) {
            int l1 = circle(s, i, i);
            int l2 = circle(s, i, i + 1);
            
            int len = max(l1, l2);
            if (len >= jans - ians + 1) {
                ians = i - (len - 1) / 2;
                jans = i + len / 2;
            }
        }
        return s.substr(ians, jans - ians + 1);
    }
    
    int circle(string& s, int left, int right) {
        while (left >= 0 && right <= s.length() && s[left] == s[right]) {
            left--; right++;
        }
        return right - left - 1;
    }
};
