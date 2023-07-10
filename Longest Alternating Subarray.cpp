class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int maxi = -1,  check = 1, len = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - nums[i-1] == check){
                len++;
                check = -1*check;
            }   
            else{
                if(len>1) i--;
                len = 1;
                check = 1;
            }
            maxi = max(maxi, len);
        }
        if(maxi <= 1) return -1;
        return maxi;
    }
};
