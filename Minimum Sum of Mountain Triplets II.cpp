class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        vector<int> first(n, nums[0]);
        for(int i=1; i<n; i++){
            first[i] = min(first[i-1], nums[i]); 
        }
        
       vector<int> last(n, nums[n-1]);
        for(int i = n-2; i>=0; i--){
           last[i] = min(last[i+1], nums[i]);
        }
        
         for(int i = 1 ; i<n-1;  i++){
            if(nums[i] > first[i] && nums[i] > last[i]){
                ans = min(ans,nums[i] + first[i] + last[i]);
            }
         }
        return ans == 1e9?-1:ans;
    }
};
