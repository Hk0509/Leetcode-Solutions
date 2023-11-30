class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ind = 1, ans = 0;
        while(n>0){
            if(n&1){ 
                ans = pow(2, ind) - ans - 1;
            }
            ind++;
            n = n>>1;
        }
        return ans;
    }
};
