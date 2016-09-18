class LRUCache{
public:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int> > l;
    int n, i = 0;
    LRUCache(int capacity) {
        n = capacity;
        i = 0;
    }

    int get(int key) {
        auto iter = m.find(key);
        if(iter != m.end()) {
            pair<int, int> p = *(iter->second);
            l.erase(iter->second);
            l.push_back(p);
            iter->second = (--l.end());
            return p.second;
        }
        return -1;
    }

    void set(int key, int value) {
        auto iter = m.find(key);
        if(iter != m.end()) {
            pair<int, int> p = *(iter->second);
            l.erase(iter->second);
            p.second = value;
            l.push_back(p);
            iter->second = (--l.end());
        }
        else {
            if(i < n) i++;
            else {
                int t = l.begin()->first;
                m.erase(t);
                l.pop_front();
            }
            pair<int, int> p(key, value);
            l.push_back(p);
            m[key] = (--l.end());
        }
    }
};

//redo
class LRUCache {
  public:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    int maxn, n = 0;
    LRUCache(int capacity) {
      maxn = capacity;
    }

    int get(int key) {
      auto iter = m.find(key);
      if(iter == m.end()) return -1;
      l.push_back(*(iter->second));
      l.erase(iter->second);
      m[key] = prev(l.end());
      return l.back().second;
    }

    void set(int key, int value) {
      auto iter = m.find(key);
      if(iter == m.end()) n++;
      else l.erase(iter->second);

      if(n > maxn) {
        m.erase(l.front().first);
        l.pop_front();
        n--;
      }
      l.push_back(make_pair(key, value));
      m[key] = prev(l.end());
    }
};


//version2
class LRUCache{
public:
    list<pair<int, int>> que;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        auto iter = cache[key];
        auto p = *iter;
        que.erase(iter);
        que.push_back(p);
        cache[key] = prev(que.end());
        return p.second;
    }
    
    void set(int key, int value) {
        if(cache.find(key) != cache.end()) {
            auto iter = cache[key];
            que.erase(iter);
        }
        que.push_back({key, value});
        cache[key] = prev(que.end());   
        // 此处不可以用que.size() 不是常数空间     
        if(cache.size() > cap) {
            auto p = que.front();
            que.pop_front();
            cache.erase(p.first);
        }
        
    }
};
