class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0, n = nums.size(), sum = 0, mini = 1e8;
        for(int i=0; i<n; i++){
            sum += nums[i];
            while(sum >= target){
                sum -= nums[s];
                mini = min(mini, i-s+1);
                s++;
            }
        }
        if(mini == 1e8) return 0;
        return mini;
    }
};
