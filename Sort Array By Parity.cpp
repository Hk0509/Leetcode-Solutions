class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l<=r){
            if(nums[l] & 1){
                if(nums[r] % 2 == 0){
                    swap(nums[l], nums[r]);
                }
                else{
                    r--;
                }
            }
            else{
                l++;
            }
        }
        return nums;
    }
};
