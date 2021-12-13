class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto comp = [](pair<int, string> &a, pair<int, string> &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
        
        unordered_map<string, int> m;
        for (auto &word : words) m[word]++;
        
        for (auto &[word, cnt] : m) {
            pq.push({cnt, word});
            
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
