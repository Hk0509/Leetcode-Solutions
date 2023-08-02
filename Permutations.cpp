class Solution {
private:
    void solve(int n, vector<int>& nums, vector<vector<int>>& ans){
        if(n<0) return ;
        if(n == 0){
            ans.push_back(nums);
            return ;
        }

        for(int i=n; i>=0; i--){
            swap(nums[i], nums[n]);
            solve(n-1, nums, ans);
            swap(nums[i], nums[n]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        solve(n-1, nums, ans);
        return ans;
    }
};
