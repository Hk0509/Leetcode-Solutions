class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int ans = 0, temp = 0, n = nums.size(); 
        bool flag  = 0;
        
        for(int i=0; i<n; i++)
        {   
            if(nums[i] == 1) 
            {
                ans += i;
                temp = i;  
            }  
            while(temp > 0)
            {
                swap(nums[i], nums[i-1]);
                i--;
                flag = 1;
                temp--;
            }
            if(flag == 1) break;
        }

        for(int i=0; i<n; i++)
        {
            if(nums[i] == n) 
            {
                ans+=(n-i-1);
                break;
            }
        }
        return ans;
    }
};
