class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, x = 0;
        for(int i=0; i<n; i++) // this loop will sort nums
        {
            int index = nums[i] - 1; //actual position
            if(nums[i] != index)
            {
                swap(nums[i], nums[index]); // put at actual position
                if(nums[i] != nums[index])
                i--;
            }        
        }
        for(int i=0; i<n; i++)
        {
            if(nums[i]-1 != i) // if element is not at its actual position, it is duplicate.
            {
                return {nums[i], i+1};
            }
        }
        return {-1};
    }
};
