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


//redo
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int ans = 0;
        sort(points.begin(), points.end(), [](const Point & a, const Point & b) {
           if(a.x != b.x) return a.x < b.x;
           else return a.y < b.y;
        });
        
        for(int i = 0; i < points.size(); i++) {
            unordered_map<double, int> m;
            int j = i+1;
            while(j < points.size() && points[i].x == points[j].x && points[i].y == points[j].y)
                j++;
            int k = j-i;
            for(;j < points.size(); j++) {
                double detax = points[j].x-points[i].x;
                double detay = points[j].y-points[i].y;
                if(detay == 0) m[double(INT_MAX)-double(INT_MIN)+1]++;
                else m[detax/detay]++;
            }
            ans = max(ans, k);
            for(auto &p:m)
                ans = max(ans, k+p.second);
        }
        return ans;
    }
};