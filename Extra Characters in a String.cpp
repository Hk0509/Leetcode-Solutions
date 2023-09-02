class Solution {
public:
    unordered_map<string, int> mpp;
    int solve(int ind, string& s, vector<string>& dictionary, vector<int>& dp){
        if(ind == s.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int take = 1e8, notTake = 1e8;
        string temp;
        for(int j=ind; j<s.size(); j++){
            temp += s[j];
            if(mpp.find(temp) != mpp.end()){
                take = min(take, solve(j+1, s, dictionary, dp));
            } 
            notTake = min(notTake, (int)temp.size() + solve(j+1, s, dictionary, dp));
        }
        return dp[ind] = min(take, notTake);
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        for(auto it: dictionary) mpp[it]++;
        vector<int> dp(n+1, -1);
        return solve(0, s, dictionary, dp);
    }
};
