class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        bool flagInc = 1, flagDec = 1;
        for(int i=1; i<n; i++){
            if(flagInc && (nums[i] - nums[i-1] < 0)) flagInc = 0;
            if(flagDec && (nums[i] - nums[i-1] > 0)) flagDec = 0;
        }
        return (flagInc | flagDec);
    }
};
