class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                sum += prices[i] - prices[i - 1];
            }
        }
        return sum;
    }
};
