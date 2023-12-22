class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), cnt0 = 0, cnt1 = 0, ans = 0;
        for(auto it: s){
            if(it == '1') cnt1++;
        }
        for(int i=0; i<n-1; i++){
            if(s[i] == '0') cnt0++;
            else cnt1--;
            ans = max(ans, cnt0 + cnt1);
        }
        return ans;
    }
};
