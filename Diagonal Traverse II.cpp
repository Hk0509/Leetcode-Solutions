class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxi = -1e9;
        for(int i=0; i<n; i++){
            int m = nums[i].size();
            maxi = max(m, maxi);
        }

        vector<vector<int>> ans(n+maxi+1);
        for(int i=0; i<n; i++){
            for(int j=0; j<nums[i].size(); j++){
                ans[i+j].push_back(nums[i][j]);
            }
        }

        vector<int> answer;
        for(auto it: ans){
            reverse(it.begin(), it.end());
            for(auto jt: it){
                answer.push_back(jt);
            }
        }
        return answer;
    }
};
