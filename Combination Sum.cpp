class Solution {
public:
    void solve(int n, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target){
        if(n < 0) return ;
        
        if(target == 0){
            ans.push_back(temp);
            return ;
        }

        solve(n-1, candidates, temp, ans, target);
        temp.push_back(candidates[n]);
        if(candidates[n] <= target)
        solve(n, candidates, temp, ans, target - candidates[n]);
        temp.pop_back();

        return ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n-1, candidates, temp, ans, target);
        return ans;
    }
};
