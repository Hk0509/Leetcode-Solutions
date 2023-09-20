class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(auto it: nums){
            sum+=it;
        }
        int l = 0;
        int currSum = 0;
        int maxLen = -1; 
        for(int r=0; r<n; r++){
            currSum += nums[r];
            while(l <= r && currSum > sum - x){
                currSum -= nums[l++];
            }
            if(currSum == sum - x){
                maxLen = max(maxLen, r-l+1);
            }
        }
        if(maxLen == -1) return -1;
        return n - maxLen; 
    }
};
