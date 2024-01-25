class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini1 = 1e9, mini2 = 1e9;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] <= mini1){
                mini2 = mini1;
                mini1 = nums[i];
            }
            else if(nums[i] < mini2){
                mini2 = nums[i];
            }
        }
        return {mini1 + nums[0] + mini2};
    }
};
