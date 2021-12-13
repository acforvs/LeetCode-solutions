class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        auto pos = ref.find(key);
        if (pos == ref.end()) return -1;
        
        int value = ref[key]->second;
        update(key, value);
        return value;
    }
    
    void put(int key, int value) {
        auto pos = ref.find(key);
        if (pos == ref.end() && dq.size() == cap) {
            pair<int, int> back = dq.back();
            dq.pop_back();
            ref.erase(back.first);
        }
        update(key, value); 
    }
    
private:
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> ref;
    int cap;
    
    void update(int key, int value) {
        auto it = ref.find(key);
        if (it != ref.end()) {
            dq.erase(it->second); 
        }
        dq.emplace_front(key, value);
        ref[key] = dq.begin();
    }
};
