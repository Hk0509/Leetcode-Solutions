class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), ans  = 0;
        vector<vector<int>> cols;
        vector<int> col, row;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                col.push_back(grid[j][i]);
            }
            cols.push_back(col);
            col.clear();
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                row.push_back(grid[i][j]);  
            }     

            for(int j=0; j<n; j++)
            {  
                if(cols[j] == row) ans++;
            }
            row.clear();
        }

        return ans;
    }
};
