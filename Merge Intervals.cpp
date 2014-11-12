bool operator < (const Interval & x, const Interval & y) {
    if(x.start != y.start)
        return x.start < y.start;
    return x.end < y.end;
 }
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end());
        int i;
        vector<Interval> ans;
        if(!intervals.size())
            return ans;
        Interval a(intervals[0].start, intervals[0].end);
        for(i = 1; i < intervals.size(); i++) {
            if(intervals[i].start <= a.end)
                a.end = max(a.end, intervals[i].end);
            else {
                ans.push_back(a);
                a.start = intervals[i].start;
                a.end = intervals[i].end;
            }
        }
        ans.push_back(a);
        return ans;
    }
};