class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;

        priority_queue<long long> pq;
        long long sum = 0;
        for (int x : target) {
            pq.push((long long) x);
            sum += (long long) x;
        }

        while (pq.top() > 1) {
            long long top = pq.top(); pq.pop();
            long long rem_sum = sum - top;

            if (rem_sum == 1LL) return true;

            long long x = top % rem_sum;

            if (x == 0 || x == top) return false;

            pq.push(x);
            sum = sum - top + x;
        }
        return true;
    }
};
