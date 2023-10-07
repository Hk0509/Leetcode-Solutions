class Solution {
private:
    void rotate(int start, int end, string& s)
    {
        while(start < end)
        {
            swap(s[start++],s[end--]);
        }
    }
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();
        if(n != m) return 0;
        for(int i=1; i<n; i++){
            rotate(0, i, s);
            rotate(i+1, n-1, s);
            rotate(0, n-1, s);
            if(s == goal) return 1;
            rotate(0, n-1, s);
            rotate(i+1, n-1, s);
            rotate(0, i, s);
        }
        return 0;
    }
};
