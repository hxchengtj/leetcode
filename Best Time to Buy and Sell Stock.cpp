class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minp = 0,maxprofit = 0;
        if(prices.size()) 
            minp = prices[0];
        for(int i = 0;i < prices.size(); i++) {
            minp = min(minp, prices[i]);
            maxprofit = max(maxprofit, prices[i]-minp);
        }
        return maxprofit;
    }
};
