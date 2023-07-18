class Solution {
public:
    static bool compare(string a, string b){
        return a.length() < b.length();
    }

    bool comp(string& a, string& b){
        if(a.size() + 1 != b.size()) return 0;
        int i=0, j = 0;
        while(j<b.size()){
            if(a[i] != b[j]) j++;
            else i++, j++;
        } 
        return (a.size() == i && b.size() == j);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        int n = words.size();
        vector<int> dp(n+1, 1);
        int maxi = 1;
        for(int i=1; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(comp(words[prev], words[i]) && dp[i] < dp[prev] + 1){
                    dp[i] = dp[prev] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
    return maxi;
    }
};
