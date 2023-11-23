class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        vector<int> temp = nums;
        int n = nums.size();

        for(int i=0; i<l.size(); i++){
            int start = l[i], end = r[i];
            bool flag = 0;
            nums = temp;
            sort(nums.begin() + start, nums.begin() + end + 1);
            int prev = nums[start+1] - nums[start];
            for(int j = start+1; j<=end; j++){
                if(nums[j] - nums[j-1] != prev){
                    flag  = 1;
                    break;
                }
            }
            if(flag) ans.push_back(0);
            else ans.push_back(1);
        }

        return ans;
    }
};
