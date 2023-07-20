#define ll long long
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        ll pro = 1, maxi = -1e8;

        for(int i=0; i<n; i++){
            pro *= nums[i];
            if(pro>maxi) maxi = pro;
            if(pro==0) pro = 1;
        }

        pro = 1;

        for(int i=n-1; i>=0; i--){
            pro *= nums[i];
            if(pro>maxi) maxi = pro;
            if(pro==0) pro = 1;
        }
        
        return maxi;
    }
};
