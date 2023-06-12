class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        bool flag = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] != 'a') flag = 1;
            if(flag == 1)
            {
                if(s[i] == 'a') break;
                else
                {
                    s[i] = s[i] - 1;
                }
            }
        }
        if(flag == 0) s[n-1] = 'z';
        return s;
    }
};
