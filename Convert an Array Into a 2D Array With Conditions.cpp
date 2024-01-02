class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        
        vector<vector<int>> ans;

        bool flag = 1;
        while(flag){
            vector<int> row;
            flag = 0;
            for(auto& it: mpp){
                if(it.second > 0){
                    row.push_back(it.first);
                    it.second--;
                    flag = 1;
                }
            }
            if(flag)
            ans.push_back(row);
        }

        return ans;
    }
};
