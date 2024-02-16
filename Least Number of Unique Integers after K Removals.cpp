class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        for(auto it: arr){
            mpp[it]++;
        }

        vector<pair<int, int>> v;
        for(auto &it: mpp){
            int freq = it.second;
            while(it.second--)
            v.push_back({freq, it.first});
        }

        sort(v.begin(), v.end());
        unordered_set<int> st;
        
        for(int i=k; i<v.size(); i++){
            st.insert(v[i].second);
        }

        return st.size();
    }
};
