class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> sell(n, INT_MIN), buy(n, INT_MIN);
        sell[0] = 0; sell[1] = max(0, prices[1]-prices[0]);
        buy[0] = -prices[0]; buy[1] = max(-prices[0], -prices[1]);
        for(int i = 2; i < n; i++) {
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
            buy[i] = max(buy[i-1], sell[i-2]-prices[i]);
        }
        return sell[n-1];
    }
};
