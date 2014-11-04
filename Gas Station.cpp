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
