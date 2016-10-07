/* review again */
//review
class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        else if(n == 3) return 2;
        int ans=1;
        while(n>=5) {
            ans*=3;
            n -= 3;
        }
        ans *= n;
        return ans;
    }
};

//version2
class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return n-1;
        if(n%3==0)
            return (int) pow(3, n/3);
        else if(n%3==1)
            return (int)pow(3, n/3-1)*4;
        else 
            return (int)pow(3, n/3)*2;
    }
};
