class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for(auto &a:intervals) {
            m[a.start]++;
            m[a.end]--;
        }
        int maxroom = 0, room = 0;
        for(auto &p:m) {
            room += p.second;
            maxroom = max(maxroom, room);
        }
        return maxroom;
    }
};
