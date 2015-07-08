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

//version2
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> profit;
        stack<pair<int, int>> stk;
        int p = 0, v = 0;
        while(v < n) {
            while(v+1 < n && prices[v+1] <= prices[v]) v++;
            p = v;
            while(p+1 < n && prices[p] <= prices[p+1]) p++;
            while(!stk.empty()) {
                if(prices[v] <= prices[stk.top().first])
                    profit.push_back(prices[stk.top().second]-prices[stk.top().first]);
                else if(prices[p] >= prices[stk.top().second]) {
                    profit.push_back(prices[stk.top().second]-prices[v]);
                    v = stk.top().first;
                }
                else break;
                stk.pop();
            }
            stk.push(make_pair(v, p));
            v = p+1;
        }
        while(!stk.empty()) {
            profit.push_back(prices[stk.top().second]-prices[stk.top().first]);
            stk.pop();
        }
        k = min(k, (int)profit.size());
        nth_element(profit.begin(), profit.begin() + k, profit.end(), greater<int>());
        int ans = 0;
        for(int i = 0; i < k; i++)
            ans += profit[i];
        return ans;
    }
};