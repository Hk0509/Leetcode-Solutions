class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis(n+1, vector<int>(m+1, 1e8));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int delR[4] = {-1, 0, 1, 0};
        int delC[4] = {0, -1, 0, 1};
        pq.push({0,{0, 0}});
        vis[0][0] = 0;
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int diff = pq.top().first;
            if(row == n-1 && col == m-1) return diff;
            pq.pop();
            for(int i=0; i<4; i++){
                int newR = row + delR[i];
                int newC = col + delC[i];
                if(newR>=0 && newR < n && newC >= 0 && newC < m){
                    int newDiff = max(diff, abs(heights[newR][newC] - heights[row][col]));
                    if(newDiff < vis[newR][newC]){
                        vis[newR][newC] = newDiff;
                        pq.push({newDiff,{newR, newC}});
                    }
                }
            }
        }
        return 0;
    }
};
