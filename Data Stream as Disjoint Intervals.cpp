/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (father.find(val) == father.end()) {
            father[val] = val;
            intervals[val] = Interval(val, val);
        }
        mergeInterval(val-1, val);
        mergeInterval(val, val+1);
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> ans;
        for (auto &p:intervals) {
            ans.push_back(p.second);
        }
        sort(ans.begin(), ans.end(), [](const Interval & a, const Interval &b) {
           return a.start != b.start? a.start < b.start: a.end < b.end;
        });
        return ans;
    }
private:
    unordered_map<int, int> father;
    unordered_map<int, Interval> intervals;
    int getFather(int id) {
        if (father.find(id) == father.end()) return -1;
        int a = id;
        while (father[a] != a) a = father[a];
        while(father[id] != id) {
            int t = father[id];
            father[id] = a;
            id = t;
        }
        return a;
    }
    void mergeInterval(int a, int b) {
        int fa = getFather(a), fb = getFather(b);
        if (fa != -1 && fb != -1) {
            father[fb] = fa;
            int s = min(intervals[fa].start, intervals[fb].start);
            int e = max(intervals[fa].end, intervals[fb].end);
            intervals.erase(fb);
            intervals[fa] = Interval(s,e);
        }
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */