class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int count = 0;
        for(int i=0; mainTank>0; i++)
        {
            count++, mainTank--;
            if((i+1)%5 == 0 && additionalTank > 0)
            {
                additionalTank--;
                mainTank++;   
            }
        }
        return count*10;
    }
};
