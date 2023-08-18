class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<pair<int, pair<int, int>>> q;

        int delR[4] = {-1, 0, 1, 0};
        int delC[4] = {0, -1, 0, 1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == -1 && !matrix[i][j]){
                    q.push({0, {i,j}});
                    vis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int steps = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for(int i = 0; i<4; i++){
                int newR = r + delR[i];
                int newC = c + delC[i];

                if(newR >= 0 && newC >= 0 && newR < n && newC < m && matrix[newR][newC] == 1 && vis[newR][newC] == -1){
                    vis[newR][newC] = steps+1;
                    q.push({steps+1, {newR, newC}});
                }
            }
        }
        return vis;
    }
};
