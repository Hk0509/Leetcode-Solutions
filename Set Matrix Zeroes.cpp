class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<pair<int, int>> zeros;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(matrix[i][j] == 0) 
                {
                    pair<int, int> p = make_pair(i,j);
                    zeros.push_back(p);
                }
            }
        }
        for(int i=0; i<zeros.size(); i++)
        {
            for(int j=0; j<r; j++)
            {
                matrix[j][zeros[i].second] = 0;
            }

            for(int j=0; j<c; j++)
            {
                matrix[zeros[i].first][j] = 0;
            }
        }     
    }
};
