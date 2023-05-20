class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(mpp[nums[i]] == 1 && mpp[nums[i]-1] == 0 && mpp[nums[i]+1] == 0)
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
