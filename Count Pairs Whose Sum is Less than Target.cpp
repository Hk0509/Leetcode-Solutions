class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size(), cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] + nums[j] < target) cnt++;
            }
        }
        return cnt;
    }
};
