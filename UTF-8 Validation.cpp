class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int mask[5] = {1 << 7, 7 << 5, 15 << 4, 31 << 3, 3 << 6};
        int a[5] = {0, 3 << 6, 7 << 5, 15 << 4, 1 << 7};
        int i = 0, n = data.size();
        while(i < n) {
            int j = 0;
            while(j < 4 && (data[i]&mask[j]) != a[j]) j++;
            if(j == 4) return false;
            i++;
            while(j-- > 0) {
                if(i == n || (data[i]&mask[4]) != a[4]) return false;
                i++;
            }
        }
        return true;
    }
};
