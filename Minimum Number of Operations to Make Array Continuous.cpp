class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(); 
        int j = 0, maxi = 1, count = 1; 

        for (int i = 1; i < n; i++){ 
            if (nums[i] == nums[i - 1]){
                continue; 
            }
            while (nums[i] - nums[j] > n - 1) {
                if(j<n && nums[j+1]==nums[j]){
                    count++;
                }
                j++;
                count--;
            }
            count++;
            maxi = max(maxi, count);
        }
        return n - maxi;
    }
};
