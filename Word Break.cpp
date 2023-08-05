class Solution {
private:
    bool solve(string& s, unordered_set<string>& st, int i, vector<int>& dp){
        if(i == s.size()) return 1;
        
        if(dp[i] != -1) return dp[i];

        for(int ind = i; ind<s.size(); ind++){
            if(st.count(s.substr(i, ind+1-i)) && solve(s, st, ind+1, dp)){
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(s, st, 0, dp);
    }
};
