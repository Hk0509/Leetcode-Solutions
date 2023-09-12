class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mpp;
        for(auto it: s){
            mpp[it]++;
        }
        vector<pair<int, char>> v;
        for(auto it: mpp){
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        int prev = 1e8;
        int ans = 0;
        for(auto it: v){
            if(prev == 0){
                ans += it.first;
                it.first = 0;
            }
            else if(it.first >= prev){
                ans += it.first - prev + 1;
                it.first = prev - 1;
            }
            prev = it.first;
        }
        return ans;
    }
};
