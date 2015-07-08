//hard
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.size() == 0)
            return 0;
        vector<int> begin(height.size());
        vector<int> value(height.size());
        int max_area = 0;
        begin[0] = 0;
        value[0] = height[0];
        int tmpb, tmpv, tmpa, j, i;
        for(i = 1;i < height.size(); i++)
        {
            if(height[i] > value[i-1])
            {
                begin[i] = i;
                value[i] = height[i];
            }
            else if(height[i] == value[i-1]) {
                begin[i] = begin[i-1];
                value[i] = value[i-1];
            }
            else {
                j = i-1;
                value[i] = height[i];
                while(j >= 0 && value[j] > height[i]) 
                {
                    tmpb = begin[j];
                    tmpv = value[j];
                    tmpa = (i-tmpb) * tmpv;
                    if(max_area < tmpa)
                        max_area = tmpa;
                    j = begin[j]-1;
                }
                if(j<0)
                    begin[i] = 0;
                else {
                    if(value[j] == height[i])
                        begin[i] = begin[j];
                    else
                        begin[i] = j + 1;
                }
            }
        }
        j = i-1;
        while(j >= 0) 
        {
            tmpb = begin[j];
            tmpv = value[j];
            tmpa = (i-tmpb) * tmpv;
            if(max_area < tmpa)
                max_area = tmpa;
            j = begin[j]-1;
        }
        return max_area;
    }
};

//version2
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        if(n == 0) return 0;
        stack<int> s;
        int left[n], right[n];
        for(int i = 0; i < n; i++) {
            while(!s.empty() && height[i] <= height[s.top()]) s.pop();
            left[i] = s.empty() ? 0 : s.top() + 1;
            s.push(i);
        }
        s = stack<int>();
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && height[i] <= height[s.top()]) s.pop();
            right[i] = s.empty() ? n : s.top();
            ans = max(ans, height[i]*(right[i]-left[i]));
            s.push(i);
        }
        return ans;
    }
};
