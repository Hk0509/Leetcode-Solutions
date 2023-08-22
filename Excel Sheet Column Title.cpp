class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n>0){
            int dig = n%26;
            if(dig == 0){
                s += 'Z';
                n = n-1;
            }
            else
            s += dig + 'A' - 1;
            n = n/26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
