class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;
        
        int n = nums.size();
        vector<int>ans(n, -1);
        int count = 0, s = 0, j = k;
        long kSum = 0;

        if(k>n/2) return ans;

        for(int i=0; i<nums.size(); i++)
        {
            if(i<k || i>=n-k) kSum += nums[i];   
            else{
                while(count++<=k) kSum += nums[j++];
                ans[i] = kSum/(2*k + 1);
                if(j == n) break;
                kSum += nums[j++] - nums[s++];
            }
        }
        return ans;
    }
};
