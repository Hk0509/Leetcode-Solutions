class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> st;
        for(auto it: nums){
            for(int i=it[0]; i<=it[1]; i++)st.insert(i);
        }
        return st.size();
    }
};
