class Solution {
private:
    bool bfs(int i, vector<int>& vis, vector<vector<int>>& graph){
        int n = graph.size();
        queue<int> q;
        q.push(i);
        vis[i] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                if(vis[it] == -1){
                    vis[it] = !vis[node];
                    q.push(it);
                }
                else if(vis[node] == vis[it]){
                    return 0;
                }
            }
        }
        return 1;           
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                if(!bfs(i, vis, graph)) return 0;
            }
        } 
        return 1;
    }
};
