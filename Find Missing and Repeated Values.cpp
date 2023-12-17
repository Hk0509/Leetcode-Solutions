class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int, int> mpp;
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mpp[grid[i][j]]++;
           }
        }
        
        int i = 1;
        int a = 0, b = 0;
        while(i<=n*n){
            if(mpp[i] == 0) a = i;
            if(mpp[i] == 2) b = i;
            i++;
        }
        return {b, a};
    }
};
