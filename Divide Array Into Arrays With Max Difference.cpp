class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0; i<n; i++){
            if(temp.empty() || nums[i] - temp.front() <= k){
                temp.push_back(nums[i]);
            }
            else{
               return {};
            }
            if(temp.size() == 3){
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};
