class Solution {
private:
    bool isValid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

    int bfs(int i, int j, vector<vector<char>>& maze){
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {i, j}});
        vis[i][j] = 1;

        int delR[4] = {-1, 0, 1, 0};
        int delC[4] = {0, -1, 0, 1};

        while(!q.empty()){
            int steps = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for(int ind = 0; ind < 4; ind++){
                int newR = r + delR[ind];
                int newC = c + delC[ind];

                if(isValid(newR, newC, n, m) && maze[newR][newC] != '+' && !vis[newR][newC]){
                    vis[newR][newC] = 1;
                    if(newR == 0 || newC == 0 || newR == n-1 || newC == m-1) return steps + 1;
                    q.push({steps + 1, {newR, newC}});
                } 
            }
        }
        return -1;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        return bfs(entrance[0], entrance[1], maze);
    }
};
