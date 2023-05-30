class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool flag = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-1] && flag == 0) flag = 1;
            else if(nums[i] == nums[i-1] && flag == 1) 
            {
                nums.erase(nums.begin()+i);
                i--;
            }
            else flag = 0;
        }
        return nums.size();
    }
};
