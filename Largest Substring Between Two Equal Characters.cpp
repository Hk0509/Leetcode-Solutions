class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int ans = -1;
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(s[j] == s[i]){
                    ans = max(j - i - 1, ans);
                }
            }
        }
        return ans;
    }
};
