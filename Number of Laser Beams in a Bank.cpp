class Solution {
public:
    int numberOfBeams(vector<string>& s) {
        int n = s.size(), cntPrev = 0, cntCurr = 0, ans = 0;
        for(int i=0; i<n; i++){
            for(auto it: s[i]){
                if(it == '1') cntCurr++;
            }
            ans += (cntPrev * cntCurr);
            if(cntCurr != 0)
            cntPrev = cntCurr;
            cntCurr = 0;
        }

        return ans;
    }
};
