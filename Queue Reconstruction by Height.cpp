class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> v = people;
        int n = people.size();
        for(int i = 0; i < n; i++) {
            auto k = -1;
            for(int j = i; j < n; j++) {
                if(people[j].second == 0 && (k == -1 || people[j].first < people[k].first))
                    k = j;
            }
            swap(people[i], people[k]);
            swap(v[i], v[k]);
            for(int j = i+1; j < n; j++)
                if(people[j].first <= v[i].first) 
                    people[j].second--;
        }
        return v;
    }
};
