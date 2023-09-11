class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<int> adj[], long long& count){
        vis[node] = 1;
        count++;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, count);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        vector<int> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            long long count = 0;
            if(!vis[i]){
                dfs(i, vis, adj, count);
                ans += (1LL)*(n - count) * count;
            }
        }
        return ans/2;
    }
};
