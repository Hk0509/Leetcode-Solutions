class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int sum = 0;

        for(int i=shifts.size() - 1; i>=0; i--)
        {
            sum+=shifts[i];
            sum = sum%26;
            shifts[i] = sum;
        }

        for(int i=0; i<s.size(); i++)
        {
            s[i] = (((s[i]) - 'a' + shifts[i])%(26)) + 'a';
        }

        return s;
    }
};
