class Solution {
public:
    string removeStars(string s) {
        string ans;
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            if(s[i] != '*')
            ans+=s[i];
            else
            {
                ans.erase(ans.end()-1);
            }
        }
        return ans;
    }
};
