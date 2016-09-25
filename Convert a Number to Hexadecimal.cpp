class Solution {
public:
    string toHex(int num) {
        char a[16];
        for(int i = 0; i < 10; i++) a[i] = '0'+i;
        for(int i = 10; i < 16; i++) a[i] = 'a'+i-10;
        string s;
        for(int i = 0; i < 32; i += 4) {
            char c = a[num & 15];
            s.push_back(c);
            num >>= 4;
        }
        while(s.back() == '0') s.pop_back();
        if(s.empty()) return "0";
        reverse(s.begin(), s.end());
        return s;
    }
};
