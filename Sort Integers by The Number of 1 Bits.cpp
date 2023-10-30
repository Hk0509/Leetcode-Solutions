class Solution {
public:
    static bool comp(int a, int b){
        if(__builtin_popcount(a) < __builtin_popcount(b)) return 1;
        else if(__builtin_popcount(a) == __builtin_popcount(b) && a<b) return 1;
        return 0; 
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};
