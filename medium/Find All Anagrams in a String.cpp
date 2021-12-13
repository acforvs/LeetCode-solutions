class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length();
        int np = p.length();
        vector<int> ans;
        if (ns < np) return ans;
        
        unordered_map<char, int> scnt;
        unordered_map<char, int> pcnt;
        
        for (auto c : p) {
            if (pcnt.find(c) == pcnt.end()) pcnt[c] = 0;
            pcnt[c] += 1;
        }
        for (int i = 0; i < ns; i++) {
            if (scnt.find(s[i]) == scnt.end()) {
                scnt[s[i]] = 0;
            }
            scnt[s[i]] += 1;
            
            if (i >= np) {
                scnt[s[i - np]] -= 1;
                if (scnt[s[i - np]] == 0) {
                    scnt.erase( scnt.find(s[i - np]) );
                }   
            }

            if (scnt == pcnt) ans.push_back(i - np + 1);
        }
        return ans;
    }
};
