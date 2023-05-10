class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        vector<int> row(n,0);
        int value = 1, startR = 0, startC = 0, endR = n-1, endC = n-1;

        for(int i=0; i<n; i++)
        {
            matrix.push_back(row);
        }

        while(value<=n*n)
        {
            for(int i=startC; i<=endC; i++)
            {
                if(value<=n*n)
                matrix[startR][i] = value++;
            }
            startR++;

            for(int i=startR; i<=endR; i++)
            {
                if(value<=n*n)
                matrix[i][endC] = value++;
            }
            endC--;

            for(int i=endC; i>=startC; i--)
            {
                if(value<=n*n)
                matrix[endR][i] = value++;
            }
            endR--;

            for(int i=endR; i>=startR; i--)
            {
               if(value<=n*n)
               matrix[i][startC] = value++;
            }
            startC++;
        }
        return matrix;
    }
};
