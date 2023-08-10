class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n-1, m = e-(e-s)/2;
        while(s<=e){
            if(nums[m] == target) return 1;
            else if(nums[s] == nums[m] && nums[m] == nums[e]){
                s = s+1;
                e = e-1;
                continue;
            }
            else if(nums[m] >= nums[s]){
                if(nums[m]>=target && nums[s]<=target){
                    e = m-1;
                }
                else{
                    s = m+1;
                }
            }
            else{
                if(nums[m]<=target && nums[e]>=target){
                    s = m+1;
                }
                else{
                    e = m-1;
                }
            }
            m = e-(e-s)/2;
        }
        return 0;
    }
};
