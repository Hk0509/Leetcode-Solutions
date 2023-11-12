class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int x = nums[i], y = nums[j];
                if(abs(x-y)<=min(x, y))
                maxi = max(nums[i]^nums[j], maxi);
            }
        }
        if(maxi == INT_MIN) return 0;
        return maxi;
    }
};
