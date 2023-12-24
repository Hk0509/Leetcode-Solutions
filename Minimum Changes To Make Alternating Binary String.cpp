class Solution {
public:
    int minOperations(string s) {
        string ans1 = "0", ans2 = "1";
        int n = s.size(), cnt1 = 0, cnt2 = 0;
        for(int i=1; i<n; i++){
            ans1 += ans1.back() == '0'? '1' : '0';
            ans2 += ans2.back() == '0'? '1' : '0';
        }

        for(int i=0; i<n; i++){
            if(s[i] != ans1[i]) cnt1++;
            if(s[i] != ans2[i]) cnt2++;
        }

        return min(cnt1, cnt2);
    }
};
