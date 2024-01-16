class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(st.find(val) == st.end()){
            st.insert(val);
            return 1;
        }
        return 0;
    }
    
    bool remove(int val) {
        if(st.find(val) != st.end()){
            st.erase(val);
            return 1;
        }
        return 0;
    }
    
    int getRandom() {
        int randIdx = rand()%st.size();
        auto it = st.begin();
        for(int i=0; i<randIdx; i++){
            it++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
