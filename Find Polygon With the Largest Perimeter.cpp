class Solution {
public:
    long long largestPerimeter(vector<int>& nums){
        sort(nums.begin(),nums.end());
        long long ans = 0, sum = nums[0];
        int n = nums.size();
        
        for(int i=1; i<n; i++){
            if(sum > nums[i]){
                ans = sum + nums[i];
            }
            sum += nums[i];
        }
        
        return ans == 0 ? -1 : ans;
        
    }
};
