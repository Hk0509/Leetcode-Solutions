class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(((nums[i] | nums[j])&1) == 0) return 1;
            }
        }
        return 0;
    }
};
