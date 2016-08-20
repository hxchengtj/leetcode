class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> idx;
    unordered_map<int, int> MAP;
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(MAP.find(val) != MAP.end()) return false;
        MAP[val] = idx.size();
        idx.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(MAP.find(val) == MAP.end()) return false;
        int id = MAP[val];
        MAP[idx.back()] = id;
        swap(idx.back(), idx[id]);
        idx.pop_back();
        MAP.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return idx[rand()%(idx.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
