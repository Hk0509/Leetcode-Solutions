class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), maxi= -1e9, maxi2 = -1e9;
        for(int i=0; i<n; i++){
            if(maxi < nums[i]){
                maxi2 = maxi;
                maxi = nums[i];
            }
            else{
                maxi2 = max(maxi2, nums[i]);
            }
        }
        return (maxi - 1) * (maxi2 - 1);
    }
};
