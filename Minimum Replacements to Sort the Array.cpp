class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n-1];
        long long cnt = 0;
        for(int i=n-2; i>=0; i--){
            int div = ceil(nums[i] / (double)last);
            cnt += div - 1;
            last = nums[i]/div;
        }
        return cnt;
    }
};
