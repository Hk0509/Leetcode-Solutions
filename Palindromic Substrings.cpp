class Solution {
public:
    bool isPalin(string& s){
        int l = 0, e = s.size()-1;
        while(l<e){
            if(s[l++] != s[e--]) return 0;
        }
        return 1;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            string temp;
            for(int j=i; j<n; j++){
                temp += s[j];
                if(isPalin(temp)) ans++;
            }
        }
        return ans;
    }
};
