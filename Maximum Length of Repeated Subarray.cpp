class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), maxi = 0;
        vector<int> curr(m+1, 0);

        for(int i=1; i<=n; i++){
            for(int j=m; j>=1; j--){
                if(nums1[i-1] == nums2[j-1]){
                    curr[j] = curr[j-1] + 1;
                    maxi = max(curr[j], maxi);
                }
                else curr[j] = 0;
            }
        }
        return maxi;
    }
};
