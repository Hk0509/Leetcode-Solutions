class Solution {
public:
    void solve(int n, int i, int k, vector<int>& temp, vector<vector<int>>& ans){
       if(i > n) return ;

       if(temp.size() == k){
           ans.push_back(temp);
           return ;
       }

       solve(n, i+1, k, temp, ans);
       temp.push_back(i+1);
       solve(n, i+1, k, temp, ans);
       temp.pop_back();

       return ;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;

        solve(n, 0, k, temp, ans);     
        return ans; 
    }
};
