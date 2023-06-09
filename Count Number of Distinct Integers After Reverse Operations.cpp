class Solution {
public:
    int reverse(int x)
    {
        int revX = 0;
        while(x>0)
        {
            int dig = x%10;
            revX = (revX*10) + dig;
            x = x/10;
        }
        return revX;
    }

    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            nums.push_back(reverse(nums[i]));
        }
        int count = 0;

        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size();i++)
        {
            while((i!=nums.size()-1) && nums[i] == nums[i+1])
            {
                i++;
            }
            count++;
        }
        return count;
    }
};
