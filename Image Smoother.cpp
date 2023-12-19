class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int sum = 0, cnt = 0;
                for(int r=-1; r<=1; r++){
                    for(int c=-1; c<=1; c++){
                        int newR = i + r;
                        int newC = j + c;
                        if(newR >= 0 && newR < n && newC >= 0 && newC < m){
                            sum += img[newR][newC]; 
                            cnt++;
                        }
                    }
                }
                ans[i][j] = sum/cnt;
            }
        }
        return ans;
    }
};
