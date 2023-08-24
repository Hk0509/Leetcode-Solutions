class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int n = words.size(), i=0;
        if(s.size() != words.size()) return 0;
        for(auto it: words){
            if(it[0] != s[i++]) return 0;
        }
        return 1;
    }
};
