class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m, -1e9);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                string temp = to_string(grid[i][j]);
                int size = temp.size();
                ans[j] = max(size, ans[j]);
            }
        }
        return ans;
    }
};
