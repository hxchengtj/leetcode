class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_set<int>> MAP;
    vector<int> idx;
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        MAP[val].insert(idx.size());
        idx.push_back(val);
        return MAP[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(MAP.find(val) == MAP.end()) return false;
        int id = *MAP[val].begin();
        if(idx.back() != idx[id]) {
          MAP[idx.back()].erase(idx.size()-1);
          MAP[idx.back()].insert(id);
          swap(idx.back(), idx[id]);
        } else id = idx.size()-1;
        idx.pop_back();
        MAP[val].erase(id);
        if(MAP[val].empty()) MAP.erase(val);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return idx[rand()%idx.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
