class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            set<int> st;
            for(int j=i; j<n; j++){
                st.insert(nums[j]);
                cnt+=(st.size()*st.size());
            }
        }
        return cnt;
    }
};
