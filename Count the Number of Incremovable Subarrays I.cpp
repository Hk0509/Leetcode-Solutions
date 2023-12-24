class Solution {
public:
    bool check(int l,int e, vector<int>&nums)
    {
        int prev = -1, n = nums.size();
        for(int i=0; i<n; i++){ 
            if(i<l || i>e){
                if(nums[i] <= prev) return 0;
                prev = nums[i];
            }
        }
        return 1;
    }
    
    int incremovableSubarrayCount(vector<int>& nums){
        int ans = 0, n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                 if(check(i,j,nums)){
                     ans++;
                 }
            }
        }
        
        return ans;
    }
};
