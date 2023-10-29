#define ll long long 
static int mod = 1e9+7;
class Solution {
public:
    int dp[26][20005];
    ll solve(char ch, int n){
        if(n == 0) return 1;

        if(dp[ch-'a'][n] != -1) return dp[ch-'a'][n];

        if(ch == 'a'){
            return dp[ch-'a'][n] = solve('e', n-1)%mod;
        }
        if(ch == 'e'){
            return dp[ch-'a'][n] = (solve('a', n-1)%mod + solve('i', n-1)%mod)%mod;
        }
        if(ch == 'i'){
            return dp[ch-'a'][n] = (solve('a', n-1)%mod + solve('e', n-1)%mod + solve('o', n-1)%mod + solve('u', n-1)%mod)%mod;
        }
        if(ch == 'o'){
            return dp[ch-'a'][n] = (solve('i', n-1)%mod + solve('u', n-1)%mod)%mod;
        }
        else{
            return  dp[ch-'a'][n] = solve('a', n-1)%mod;
        }
    }
    int countVowelPermutation(int n) {
        memset(dp, -1, sizeof(dp));
        return (solve('a', n-1)%mod + solve('e', n-1)%mod + solve('i', n-1)%mod + solve('o', n-1)%mod + solve('u', n-1)%mod)%mod;
    }
};
