class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mpp;
        for(auto it: matches){
           mpp[it[1]]++;
           if(mpp.find(it[0]) == mpp.end())
           mpp[it[0]] = 0;
        }

        vector<int> loss0, loss1;
        for(auto it: mpp){
            if(it.second == 0) loss0.push_back(it.first);
            if(it.second == 1) loss1.push_back(it.first);
        }
        
        return {loss0, loss1};
    }
};
