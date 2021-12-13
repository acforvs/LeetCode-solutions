typedef pair<int, int> pii;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        
        int ind = 0;
        priority_queue<pii, vector<pii>, greater<pii>> enq;
        
        long long cur_time = 0;

        vector<int> ans;
        while (ind < n || !enq.empty()) {
            if (enq.empty()) {
                cur_time = max(cur_time, (long long) tasks[ind][0]);
            }
            
            while (ind < n && (long long) tasks[ind][0] <= cur_time) {
                enq.push({tasks[ind][1], tasks[ind][2]});
                ind++;
            }
            
            pii processing = enq.top(); 
            enq.pop();
            
            ans.push_back(processing.second);
            cur_time += (long long) processing.first;
        }
        return ans;
    }
};
