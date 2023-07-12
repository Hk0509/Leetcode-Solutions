class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int len = n+m - dp[n][m], i = n, j = m, index = len-1;
        string ans;
        for(int i=0; i<len; i++) ans+='.';
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans[index] = str1[i-1];
                i--, j--, index--; 
            }

            else if(dp[i-1][j] > dp[i][j-1]){
                ans[index] = str1[i-1];
                i--, index--;
            }

            else{
                ans[index] = str2[j-1];
                j--, index--;
            }
        }

        while(i>0){
            ans[index] = str1[i-1];
            index--, i--;
        }

        while(j>0){
            ans[index] = str2[j-1];
            j--, index--;
        }

        return ans;
    }
};
