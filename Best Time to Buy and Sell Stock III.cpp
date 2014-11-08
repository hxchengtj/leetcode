//hard
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 0)
            return 0;
        vector<int> lprofit(prices.size()), rprofit(prices.size());
        int i, minp, maxp;
        minp = prices[0];
        maxp = prices[prices.size()-1];
        for(i = 1; i < prices.size(); i++) {
            lprofit[i] = max(prices[i] - minp, lprofit[i-1]);
            minp = min(minp, prices[i]);
        }
        for(i = prices.size()-2; i >= 0; i--) {
            rprofit[i] = max(maxp - prices[i], rprofit[i+1]);
            maxp = max(maxp, prices[i]);
        }
        int profit = rprofit[0];
        for(i = 0; i < prices.size()-1; i++)
            profit = max(profit, lprofit[i]+rprofit[i+1]);
        return profit;
    }
};
