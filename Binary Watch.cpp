class Solution {
public:
    int cntOne(int a) {
        int ans = 0;
        for(int i = 0; i < 10; i++) {
            if(a&(1 << i)) ans++;
        }
        return ans;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for (int h = 0; h < 12; h++)
            for (int m = 0; m < 60; m++)
                if(cntOne(m << 4 | h) == num)
                    ans.push_back(to_string(h)+":"+(m < 10?"0":"")+to_string(m));
        return ans;
    }
};
