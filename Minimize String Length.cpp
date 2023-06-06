class Solution {
public:
    int minimizedStringLength(string s) {
        map<char, int>mpp;
        for(int i=0; i<s.size(); i++) mpp[s[i]]++;
        return mpp.size();
    }
};
