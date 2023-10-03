class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        for(auto it: mpp){
            ans += ((it.second)*(it.second-1))/2;
        }
        return ans;
    }
};
