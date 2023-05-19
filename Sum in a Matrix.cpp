class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int r = nums.size();
        int c = nums[0].size();
        for(int i=0; i<r; i++)
        {
            sort(nums[i].begin(), nums[i].end());
        }

        int score = 0;
        for(int i=0; i<c; i++)
        {
            int max = INT_MIN;
            for(int j=0; j<r; j++)
            {
                if(nums[j][i] > max)
                max = nums[j][i];
            }
            score += max;
        }
        return score;
    }
};
