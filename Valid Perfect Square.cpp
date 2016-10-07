class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0) return true;
        int l = 1, r = num;
        while(l <= r) {
            int m = l+(r-l)/2;
            if(m == num/m) {
                if(num%m) return false;
                else return true;
            }
            else if(m > num/m) r = m-1;
            else l = m+1;
        }
        return false;
    }
};

//version2
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(m < num/m) l = m+1;
            else r = m-1;
        }
        return l == num/l && num%l == 0;
    }
};
