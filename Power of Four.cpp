class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return 0;
        int x = 0;
        while(n>1){
            if(x!=0) return 0;
            x = n%4;
            n = n/4;
        }
        return x==0;
    }
};
