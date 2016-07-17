class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        if(n == 0) return "0A0B";
        int a = 0, b = 0, dict[128];
        memset(dict, 0, sizeof(dict));
        for(char c:secret) dict[c]++;
        for(int i = 0; i < n; i++) {
            if(secret[i] == guess[i]) {
                a++;
                dict[secret[i]]--;
                if(dict[secret[i]] < 0) b--;
            } 
            else if(dict[guess[i]] > 0) {
                dict[guess[i]]--;
                b++;
            }
        }
        
        return to_string(a)+'A'+to_string(b)+'B';
    }
};
