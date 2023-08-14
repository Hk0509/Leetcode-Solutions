class Solution {
private:
    void dfs(int i, vector<int>& vis, vector<int> adj[]){
        vis[i] = 1;
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && isConnected[i][j])
                adj[i].push_back(j);
            }
        }

        vector<int> vis(n, 0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(vis[i]  == 0){
                count++;
                dfs(i, vis, adj);
            }
        }

        return count;
    }
};
