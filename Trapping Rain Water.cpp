class Solution {
public:
    int trap(int A[], int n) {
        int i, j, maxa = A[0], num = 0, sum[n], ans = 0;
        sum[0] = A[0]; 
        for(i = 1; i < n; i++) {
            if(maxa < A[i]) {
                num = i;
                maxa = A[i];
            }
            sum[i] = sum[i-1]+A[i];
        }
        stack<int> s;
        s.push(num);
        for(i = num-1;i >= 0; i--) {
            while(!s.empty() && A[s.top()] < A[i])
                s.pop();
            s.push(i);
        }
        while(s.size() >= 2)  {
            i = s.top();
            s.pop();
            j = s.top();
            ans += (j-i-1) * A[i] - sum[j-1] + sum[i];
        }        
        for(i = num+1;i < n; i++) {
            while(!s.empty() && A[s.top()] < A[i])
                s.pop();
            s.push(i);
        }
        while(s.size() >= 2)  {
            j = s.top();
            s.pop();
            i = s.top();
            ans += (j-i-1) * A[j] - sum[j-1] + sum[i];
        }
        return ans;
    }
};

//review
//version2
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int i = 0, j = (int)height.size()-1;
        int lm = 0, rm = 0;
        while(i < j) {
            if(height[i] <= height[j]) {
                lm = max(lm, height[i]);
                ans += lm-height[i++];
            }
            else {
                rm = max(rm, height[j]);
                ans += rm-height[j--];
            }
        }
        return ans;
    }
};