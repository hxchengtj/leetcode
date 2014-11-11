//review
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i, t, j, k;
        for(i = num.size()-2; i >= 0; i-- ) 
            if(num[i] < num[i+1]) {
                for(j = i+1; j < num.size(); j++)
                    if(num[j] <= num[i])
                        break;
                j--;
                t = num[i];
                num[i] = num[j];
                num[j] = t;
                break;
            }
        for(j = i+1, k = num.size()-1; j < k;j++, k--){
            t = num[j];
            num[j] = num[k];
            num[k] = t;
        }
    }
};