class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        
        int sum = nums[0];
        for(int i = 1; i<n; i++){
            if(nums[i] - nums[i-1] == 1){
                sum += nums[i];
            }
            else{
                break;
            }
        }
        
        int ans = sum;
        while(1){
            if(mpp.find(ans) != mpp.end()){
                ans++;
            }
            else{
                return ans;
            }
        }
    }
};
