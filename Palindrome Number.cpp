class Solution {
public:
    bool isPalindrome(int x) {
        long y = 0;
        long temp = x;
        long n = 0;

        while(temp>0)
        {
            temp = temp/10;
            n++;  
        }
        temp = x;

        for(long i=1; i<=n; i++)
        {
            int dig = temp%10;
            y = y + dig*pow(10,n-i);
            temp = temp/10;
        }

        if(y==x)
        return 1;
        else
        return 0;
    }
};
