class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        vector<pair<int, int>> v;
        for(int i=0; i<groupSizes.size(); i++){
            v.push_back({groupSizes[i], i}); 
        }
        sort(v.begin(), v.end());
        int size = 0;
        vector<int> temp;
        for(auto it: v){
            if(size == 0){
                size = it.first;
                if(!temp.empty()){
                    ans.push_back(temp);
                    temp.clear();
                }
            }
            temp.push_back(it.second);
            size--;
        }
        ans.push_back(temp);
        return ans;
    }
};
