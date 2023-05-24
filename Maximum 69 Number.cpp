class Solution {
public:

    int countDigits(int num, int& digAt)
    {
        int count = 0;
        while(num>0)
        {
            int dig = num%10;
            num = num/10;
            count++;
            if(dig == 6)
            digAt = count;
        }
        return count;
    }

    int maximum69Number (int num) {
        int digAt = 0;
        int n = countDigits(num, digAt);
        
        return num + (3*pow(10,digAt-1));
    }
};
