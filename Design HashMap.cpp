#include<vector>
class MyHashMap {
public:
    vector<int> mpp;
    
    void put(int key, int value) {
       if(key<mpp.size()) mpp[key] = value;
       else{
           for(int i=mpp.size(); i<=key; i++){
               mpp.push_back(-1);
           }
           mpp[key] = value;
       }
    }
    
    int get(int key) {
        return key<mpp.size() ? mpp[key] : -1;
    }
    
    void remove(int key) {
        if(key<mpp.size()){
            mpp[key] = -1;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
