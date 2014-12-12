class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int i, j, n = points.size(), ans = 0, k, l;
        unordered_map<double, int> m;
        for(i = 0; i < points.size(); i++) {
            m.clear();
            k = 1;
            for(j = i+1; j < points.size(); j++) {
                if(points[j].y == points[i].y) {
                    if(points[j].x == points[i].x) k++;
                    else m[INT_MAX+1.0-INT_MIN]++;
                }
                else m[(1.0*points[j].x-points[i].x)/(points[j].y-points[i].y)]++;
            }
            l = 0;
            for(unordered_map<double, int>::iterator iter = m.begin(); iter != m.end(); iter++)
                l = max(l, iter->second);
            ans = max(ans, l+k);
        }
        return ans;
    }
};