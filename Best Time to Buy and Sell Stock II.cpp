//review
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minp, profit = 0;
        if(prices.size())
            minp = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(minp < prices[i]) {
                profit += prices[i] - minp;
                minp = prices[i];
            }
            else
                minp = prices[i];
        }
        return profit;
    }
};
