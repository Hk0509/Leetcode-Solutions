class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size(), cnt = 0, ele = 0;
        for(int i=0; i<n; i++){
            if(cnt == 0){
                ele = nums[i];
                cnt = 1;
            } 
            else if(ele == nums[i]){
                cnt++;
            }
            else cnt--;
        }
        
        int maxi = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == ele) maxi++;
        }
        
        int count = 0, ans = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == ele) count++;
            if(count * 2 > i+1){
                ans = i;
                if((maxi - count) * 2 > n-i-1)
                    break;
                else ans = -1;
            }
        }
        return ans;
    }
};
