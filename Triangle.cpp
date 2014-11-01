class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> sum(triangle.size()+1);
        int i, j;
        for(i = triangle.size()-1; i >= 0; i--)
            for(j = 0;j < triangle[i].size();j++)
                sum[j] = min(sum[j], sum[j+1]) + triangle[i][j];            
        return sum[0];
    }    
};

