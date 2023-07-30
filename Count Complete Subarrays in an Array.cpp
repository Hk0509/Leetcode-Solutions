class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_set<int> st;
        for(int i=0; i<n; i++) st.insert(nums[i]);

        for(int i=0; i<n; i++){
        unordered_set<int> temp;
            for(int j=i; j<n; j++){
                temp.insert(nums[j]);
                if(temp.size() == st.size()) ans++;
            }
        }

        return ans;
    }
};
