class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0; i<n-2; i++){
            for(int j = i+1; j<n-1; j++){
                int s = j+1, e = n - 1, m = (s+e)/2;
                int target = (-1)*(nums[i] + nums[j]);
                while(s<=e){
                    if(i == m || j == m) break;
                    m = (s+e)/2;
                    if(nums[m] == target){
                        st.insert({nums[i], nums[j], nums[m]});
                        break;
                    }
                    else if(nums[m] < target){
                        s = m + 1;
                    }
                    else{
                        e = m-1;
                    }
                }
            }
        }
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};
