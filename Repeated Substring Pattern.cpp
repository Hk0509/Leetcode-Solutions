class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string temp;
        for(int i = 0; i<n/2; i++){
            temp+=s[i];
            string ans = temp;
            while(ans.size()<n){
                ans+=temp;
            }
            if(ans == s) return 1;
        }
        return 0;
    }
};
