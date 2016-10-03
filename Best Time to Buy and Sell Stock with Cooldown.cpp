/* review again */
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

//version2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> hold(2, INT_MIN), sell(2, 0);
        int n = prices.size();
        for(int i = 0; i < n; i++) {
            hold[i&1] = max(sell[i&1]-prices[i], hold[(i+1)&1]);
            sell[i&1] = max(hold[(i+1)&1]+prices[i], sell[(i+1)&1]);
        }
        return sell[(n-1)&1];
    }
};
