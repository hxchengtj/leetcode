/* review again */
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

//version2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold0 = INT_MIN, hold1 = INT_MIN;
        int sell0 = 0, sell1 = 0;
        for(int i = 0;i < prices.size(); i++) {
            hold0 = max(hold0, -prices[i]);
            sell0 = max(sell0, hold0+prices[i]);
            hold1 = max(hold1, sell0-prices[i]);
            sell1 = max(sell1, hold1+prices[i]);
        }
        return sell1;
    }
};

//version2
//redo
int maxProfit(vector<int>& prices) {
  int hold0 = INT_MIN, sell0 = 0, hold1 = INT_MIN, sell1 = 0;
  for(auto p:prices) {
    hold0 = max(hold0, -p);
    sell0 = max(sell0, hold0+p);
    hold1 = max(hold1, sell0-p);
    sell1 = max(sell1, hold1+p);
  }
  return sell1;
}

