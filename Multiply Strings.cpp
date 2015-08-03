class Solution {
public:
    string multiply(string num1, string num2) {
        int f[num1.size()+num2.size()];
        int i, j, k, a = 0, b, c;
        for(i = 0; i < num1.size()+num2.size(); i++)
            f[i] = 0;
        for(i = num1.size()-1; i >= 0; i--) {
            a = 0;
            for(j = num2.size()-1; j >= 0; j--) {
                b = num1[i]-'0';
                c = num2[j]-'0';
                a = b*c + a + f[i+j+1];
                f[i+j+1] = a%10;
                a = a/10;
            }
            k = i+j+1;
           // while(a > 0 && k >=0) {
                a = f[k]+a;
                f[k] = a%10;
                a = a/10;
                k--;
           // }
        }
        bool x = true;
        string s;
        for(i = 0; i < num1.size()+num2.size(); i++) {
            if(x && !f[i])
                continue;
            x = false;
            s += (f[i] + '0');
        }
        if(!s.size())
            s += '0';
        return s;
    }
};

//redo
string multiply(string num1, string num2) {
  int n1 = num1.size(), n2 = num2.size();
  while(n1 > 0 && num1[0] == '0') n1--;
  while(n2 > 0 && num2[0] == '0') n2--;
  if(n1 == 0 || n2 == 0) return "0";
  num1.resize(n1); num2.resize(n2);
  reverse(num1.begin(), num1.end()); reverse(num2.begin(), num2.end());
  string ans;
  for(int i = 0; i < n1; i++) {
    int k = i, r = 0;
    for(int j = 0; j < n2; j++) {
      if(k < ans.size()) {
        int a = (num1[i]-'0')*(num2[j]-'0')+ans[k]-'0'+r;
        ans[k] = a%10+'0';
        r = a/10;
      } else {
        int a = (num1[i]-'0')*(num2[j]-'0')+r;
        ans.push_back(a%10+'0');
        r = a/10;
      }
      k++;
    }
    if(r) ans.push_back(r+'0');
  }
  reverse(ans.begin(), ans.end());
  return ans;
}


