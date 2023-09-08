#define ll long long
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        ll ans = 0, sum = 0;
        int n = nums.size();
        map<int, int> mpp;
        for(int i=0; i<n; i++){
            if(i<k){
                mpp[nums[i]]++;
                sum += nums[i];
            }
            else{
                if(mpp[nums[i-k]] > 1) mpp[nums[i-k]]--;
                else
                    mpp.erase(nums[i-k]);

                mpp[nums[i]]++;
                sum += nums[i];
                sum -= nums[i-k];
            }
            if(mpp.size() >= m){
                ans = max(sum, ans);
            }
        }
        return ans;
    }
};
