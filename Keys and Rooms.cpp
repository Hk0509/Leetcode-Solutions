class Solution {
private:
    void dfs(int i, vector<vector<int>>& rooms, vector<int>& vis){
        vis[i] = 1;
        for(auto it: rooms[i]){
            if(!vis[it]){
                dfs(it, rooms, vis);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        dfs(0, rooms, vis);

        for(auto it: vis){
            if(!it) return 0;
        }

        return 1;
    }
};
