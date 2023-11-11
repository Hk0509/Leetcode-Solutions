class Solution {
public:
    int n;
    void getTopo(vector<int> &inDegree, vector<int> &topo, vector<int> adj[])
    {
        queue<int> q;
        for(int i = 0 ; i <= n ; i++)
        {
            if(inDegree[i] == 1)
            {
                q.push(i);
                break;
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto jt: adj[node])
            {
                inDegree[jt]--;
                if(inDegree[jt] == 1) q.push(jt);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<vector<int>> dup = adjacentPairs;
        n = adjacentPairs.size();
        map<int,int> m;
        map<int,int> rm;
        int cnt = 0;
        for(auto it: dup)
        {
            for(auto jt: it)
            {
                if(m.find(jt) == m.end())
                {
                    m[jt] = cnt;
                    cnt++;
                }
            }
        }
        for(auto &it: dup)
        {
            for(auto &jt: it)
            {
                int ele = jt;
                jt = m[jt];
                rm[m[ele]] = ele;
            }
        }
        vector<int> adj[n+1];
        vector<int> inDegree(n+1,0);
        for(auto it: dup)
        {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            inDegree[u]++, inDegree[v]++;
        }
        vector<int> topo, ans;
        getTopo(inDegree,topo,adj);
        int k = topo.size();
        vector<int> vis(k+1,0);
        for(int i = 0 ; i < k ; i++)
        {
            vis[topo[i]] = 1;
        }
        for(int i = 0 ; i < k+1 ; i++)
        {
            if(vis[i] == 0)
            {
                topo.push_back(i);
                break;
            }
        }
        for(auto it: topo)
        {
            ans.push_back(rm[it]);
        }
        return ans;

    }
};
