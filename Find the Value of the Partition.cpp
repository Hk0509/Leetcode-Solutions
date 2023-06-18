class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int val = INT_MAX;
        for(int i = 0 ; i < nums.size() -1 ; i++) val = min(val,nums[i+1] - nums[i]);
        return val;
    }
};
