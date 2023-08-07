#define MOD 1000000007
#define ll long long
class Solution {
private:
    ll solve(int currL, int usedSongs, int n, int k, int goal, vector<vector<ll>>& dp){
        //Base case
        if(currL == goal){
            return usedSongs == n;
        }

        if(dp[currL][usedSongs] != -1) return dp[currL][usedSongs];

        ll used = (solve(currL + 1, usedSongs, n, k, goal, dp)%MOD * max(0, usedSongs-k)%MOD)%MOD;
        ll newS = (solve(currL + 1, usedSongs+1, n, k, goal, dp)%MOD * (n - usedSongs)%MOD)%MOD;

        return dp[currL][usedSongs] = (used + newS) % MOD;  
    }
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<ll>> dp(101, vector<ll>(101, -1));
        return (int)solve(0, 0, n, k, goal, dp);
    }
};
