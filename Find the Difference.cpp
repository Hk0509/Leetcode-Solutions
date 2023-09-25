class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for(int i=0; i<s.size(); i++){
            sum ^= (s[i] ^ t[i]);
        }
        sum ^= t.back();
        return sum;
    }
};
