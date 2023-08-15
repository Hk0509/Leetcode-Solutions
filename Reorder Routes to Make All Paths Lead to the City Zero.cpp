class Solution {
private:
    void dfs(int i, vector<int>& vis, vector<pair<int, int>> adj[], int& count){
        vis[i] = 1;

        for(auto it: adj[i]){
            if(!vis[it.first]){
                count+=it.second;
                dfs(it.first, vis, adj, count);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];

        for(auto it: connections){
            adj[it[0]].push_back({it[1], 0});
            adj[it[1]].push_back({it[0], 1});
        }

        vector<int> vis(n, 0);
        
        int count = 0;
        dfs(0, vis, adj, count);

        return n - count - 1;
    }
};
