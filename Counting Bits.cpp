class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1, 0);
        if(num == 0) return v;
        v[1] = 1;
        int j = 1, k = 1;
        for(int i = 2; i <= num; i++) {
            if(i == k*2) {
                v[i] = 1;
                k *= 2;
                j=1;
            } else {
                v[i] = v[j]+1;
                j += 1;
            }
        }
        return v;
    }
    
};
