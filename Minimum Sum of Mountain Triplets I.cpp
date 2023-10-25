class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k = j+1; k<n;k++){
                    if(nums[i] < nums[j] && nums[k]<nums[j]){
                        ans = min(ans,nums[i]+nums[j]+nums[k]);
                    }
                }
            }
        }
    return ans == 1e9?-1:ans;
    }
};
