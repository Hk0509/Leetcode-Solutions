class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> outDegree(n, 0);
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                outDegree[i]++;
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                bool check = 0;
                for(auto it: adj[i]){
                    if(it == j){
                        check = 1;
                        break;
                    }
                }
                if(!check)
                    ans = max(outDegree[i] + outDegree[j], ans);
                else
                    ans = max(outDegree[i] + outDegree[j] - 1, ans);
            }
        }
        
        return ans;
    }
};
