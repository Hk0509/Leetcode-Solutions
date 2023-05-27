class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> positive;
        long long pro = 1;
        int zero = 0;
        bool one = 0;
        vector<int> negative;
        sort(nums.begin(), nums.end());
        
        for(auto it:nums)
        {
            if(it == 1) one = 1;
            if(it == 0) zero++;
            if(it>0) pro = pro*it;
            else if(it<0) negative.push_back(it);  
        }
            
        for(auto it:negative)
        {
            pro = pro*it;
        }
        
        if((negative.size() + zero) == nums.size() && negative.size()<2) return 0;
        
        if(negative.size() % 2 == 0) return pro;
        else return (pro/negative[negative.size()-1]);
    }
};
