class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size(), ans = 0;
        vector<string> v;
        for(int i=0; i<n; i++){
            string temp;
            int vow = 0, cons = 0;
            for(int j=i; j<n; j++){
                temp+=s[j];
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u') vow++;
                else cons++;
                if(vow == cons && (vow*cons)%k == 0)
                ans++;
            }
        }
        return ans;
        
    }
};
