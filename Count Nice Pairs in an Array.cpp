class Solution {
public:
    const int mod = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        vector<int> rev;
        int n = nums.size();
        for(int i=0; i<n; i++){
            string temp = to_string(nums[i]);
            reverse(temp.begin(), temp.end());
            rev.push_back(stoi(temp));
        }
        int ans = 0;
        vector<int> diff;
        map<int, int> mpp;
        for(int i=0; i<n; i++){
            diff.push_back(nums[i] - rev[i]);
            mpp[diff.back()]++;
        }

        for(auto it: mpp){
            cout<<it.second<<" ";
            ans = (ans + (it.second*1ll*(it.second-1)/2))%mod;
        }
        return ans;
    }
};
