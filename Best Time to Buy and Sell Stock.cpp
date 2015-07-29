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


//redo
int maxProfit(vector<int>& prices) {
  int hold = INT_MIN, sell = 0;
  for(auto &p:prices) {
    hold = max(hold, -p);
    sell = max(sell, hold+p);
  }
  return sell;
}

