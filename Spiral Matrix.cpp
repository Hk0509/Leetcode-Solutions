class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> ans;
        int startR = 0, startC = 0, endR = r-1, endC = c-1;
        while(ans.size()<r*c)
        {
            for(int i=startC; i<=endC; i++)
            {
                if(ans.size()<r*c)
                ans.push_back(matrix[startR][i]);
            }
            startR++;

            for(int i = startR; i<=endR; i++)
            {
                if(ans.size()<r*c)
                ans.push_back(matrix[i][endC]);
            }
            endC--;

            for(int i = endC; i>=startC; i--)
            {
                if(ans.size()<r*c)
                ans.push_back(matrix[endR][i]);
            }
            endR--;

            for(int i = endR; i>=startR; i--)
            {
                if(ans.size()<r*c)
                ans.push_back(matrix[i][startC]);
            }
            startC++;
        } 
        return ans;
    }
};
