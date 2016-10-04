/* review again */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if(n == 0) return 0;
        vector<int> mask(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(char c:words[i]) mask[i] |= (1 << (c-'a'));
            for(int j = 0; j < i; j++) 
                // 注意此处要转换成int
                if (!(mask[i] & mask[j])) ans = max(ans, int(words[i].size()*words[j].size()));
        }
        return ans;
        
    }
};
