class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {;
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        
        if(start < 0 || end < 0 || nums[end] != target || nums[start] != target)
        return {-1, -1};
        else
        return {start, end};
    }
};
