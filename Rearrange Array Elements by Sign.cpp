class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg;
        vector<int> pos;
        vector<int> ans;
        for(auto it: nums)
        {
            if(it>0) pos.push_back(it);
            else neg.push_back(it);
        }
        for(int i=0; i<nums.size()/2; i++)
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};
