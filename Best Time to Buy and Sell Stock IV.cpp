// reviewß
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k >= n/2) {
            int ret = 0;
            for(int i = 1; i < n; i++) 
                ret += max(prices[i]-prices[i-1], 0);
            return ret;
        }
        int hold[k], sell[k];
        for(int i = 0; i < k; i++) {
            hold[i] = INT_MIN;
            sell[i] = INT_MIN;
        }
        for(int i = 0;i < n; i++) {
            hold[0] = max(hold[0], -prices[i]);
            sell[0] = max(sell[0], hold[0]+prices[i]);
            for(int j = 1; j < k; j++) {
                hold[j] = max(hold[j], sell[j-1]-prices[i]);
                sell[j] = max(sell[j], hold[j]+prices[i]);
            }
        }
        return sell[k-1];
    }
};