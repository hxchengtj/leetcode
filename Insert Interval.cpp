class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int i;
        vector<Interval> ans;
        for(i = 0; i < intervals.size() && intervals[i].start <= newInterval.end; i++)
            if(intervals[i].end >= newInterval.start) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
            else
                ans.push_back(intervals[i]);
        ans.push_back(newInterval);
        for(; i < intervals.size(); i++)
            ans.push_back(intervals[i]);
        return ans;
    }
};

//redo
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
  vector<Interval> ans;
  int i = 0;
  for(i = 0; i < intervals.size() && intervals[i].end < newInterval.start; i++) ans.push_back(intervals[i]);
  for(; i < intervals.size() && intervals[i].start <= newInterval.end; i++) {
    newInterval.start = min(intervals[i].start, newInterval.start);
    newInterval.end = max(intervals[i].end, newInterval.end);
  }
  ans.push_back(newInterval);
  for(;i < intervals.size(); i++) ans.push_back(intervals[i]);
  return ans;
}

