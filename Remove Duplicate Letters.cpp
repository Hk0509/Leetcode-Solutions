class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        unordered_map<char, bool> vis;
        unordered_map<char, int> mpp;
        for(int i = 0; i<n; i++){
            mpp[s[i]]++;
        }
        string ans;
        int ind = 0;
        for(int i=0; i<n; i++){
            while(!vis[s[i]] && !ans.empty() && ans.back()>s[i] && mpp[ans.back()]>=1){
                vis[ans.back()] = 0;
                ans.pop_back();
            }
            if(!vis[s[i]] && ans.size()<mpp.size())
            ans.push_back(s[i]);
            mpp[s[i]]--;
            vis[s[i]] = 1;
        }
        return ans;
    }
};
