class Solution {
public:
    int reverse(int x) {
        string temp = to_string(x);
        char sign = '+';
        if(temp[0] == '-'){
            sign = '-';
            temp.erase(temp.begin());
        }
        if(temp.size() > 10) return 0;
        long ans = 0;
        for(int i=temp.size()-1; i>=0; i--){
            ans += temp[i] - '0';
            if(i > 0)
            ans*=10;
            if(ans>INT_MAX) return 0;
        }
        if(sign == '-') ans = -1 * ans;
        return ans;
    }
};
