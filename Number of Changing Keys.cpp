class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.size(), ans = 0;
        s[0] = tolower(s[0]);
        for(int i=1; i<n; i++){
            s[i] = tolower(s[i]);
            if(s[i] != s[i-1]) ans++;
        }
        
        return ans;
    }
};
