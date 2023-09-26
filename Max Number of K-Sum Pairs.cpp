class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int ans = 0, n = nums.size();
        for(auto it: nums) mpp[it]++;
        for(int i=0; i<n; i++){
            if(mpp[k - nums[i]] > 0){
                mpp[nums[i]]--;
                mpp[k - nums[i]]--;
                if(mpp[nums[i]]>=0)
                ans++;
            }
        }
        return ans;
    }
};
