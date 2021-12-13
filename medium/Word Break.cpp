class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        if (dict.find(s) != dict.end()) {
            return true;
        }

        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            if (dp[i] == 1) {
                string str = "";
                for (int j = i; j < n; ++j) {
                    str += s[j];
                    if (dict.find(str) != dict.end()) {
                        dp[j + 1] = 1;
                    }
                }
            }
        }
        
        return dp[n] == 1;
    }
};
