class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (ind.find(val) != ind.end()) {
            return false;
        }
        el.push_back(val);
        ind[val] = el.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (ind.find(val) == ind.end()) {
            return false;
        }
        int i = ind[val];
        el[i] = el.back();
        el.pop_back();
        ind[el[i]] = i;
        ind.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return el[rand() % el.size()];
    }

private:
    unordered_map<int, int> ind;
    vector<int> el;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
