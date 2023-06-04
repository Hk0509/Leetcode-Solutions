class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int size = queries.size();
        int rows = n, cols = n;
        vector<bool> rowVis(n,0), colVis(n,0);
        long ans = 0;
        for(int i=size-1; i>=0; i--)
        {
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];
            
            if(type == 0)
            {
              if(rowVis[index] == 0)
              {
                rowVis[index] = 1;
                ans += val*rows;
                cols--;
              }
            }
            else
            {
                if(colVis[index] == 0)
                {
                    colVis[index] = 1;
                    ans += val*cols;
                    rows--;
                }
            }
        }
        return ans;
    }
};
