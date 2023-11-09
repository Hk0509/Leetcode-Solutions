class Solution {
public:
    const int mod = 1e9+7;
    int countHomogenous(string s) {
        int n = s.size();
        long long ans = 0, cnt = 1;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]) cnt++;
            else{
                ans = (ans + (cnt*1ll*(cnt+1)/2)%mod)%mod;
                cnt = 1;
            }
        }
        ans = (ans + (cnt*1ll*(cnt+1)/2)%mod)%mod;
        return ans;
    }
};
