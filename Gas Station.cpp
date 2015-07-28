class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i, j = -1, sum = 0, sum1 = 0;
        for(i = 0; i < gas.size(); i++) {
            gas[i] -= cost[i];
            if(sum == 0 && gas[i] >= 0)
                j = i;
            sum += gas[i];
            sum1 += gas[i];
            if(sum < 0) {
                sum = 0;
                j = -1;
            }
        }
        if(sum1 < 0)
            j = -1;
        return j;
    }
};

//redo
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int totsum = 0, cursum = 0, ans = -1;
  int n = gas.size();
  for(int i = 0; i < n; i++) {
    int a = gas[i]-cost[i];
    totsum += a;
    if(cursum == 0 && a >= 0)
      ans = i;
    cursum = max(0, cursum+a);
  }
  return totsum < 0 ? -1:ans;
}

