class Solution {
public:
    bool halvesAreAlike(string s) {
        int j = s.size()/2;
        int i = 0;
        int cnt1 = 0, cnt2 = 0;
        while(j < s.size()){
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);
            if((s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i'))
            cnt1++;
            if((s[j] == 'a' || s[j] == 'e' || s[j] == 'o' || s[j] == 'u' || s[j] == 'i'))
            cnt2++;

            i++, j++;
        }
        return cnt1 == cnt2;
    }
};
