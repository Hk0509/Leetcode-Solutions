class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> ans;
        for(auto it: nums) sum += it;

        int prevSum = 0, len = n;
        for(int i=0; i<n; i++){
            int suf = nums[i]* (n - len) - prevSum;
            int pref = abs(nums[i] * len - sum); 
            ans.push_back(suf + pref);
            sum -= nums[i]; 
            prevSum += nums[i];
            len--;
        }

        return ans;
    }
};
