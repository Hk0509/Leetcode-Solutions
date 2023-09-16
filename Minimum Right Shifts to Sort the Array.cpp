class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        sort(v.begin(), v.end());
        vector<int> diff;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(nums[i] == v[j]){
                    if(i<=j)
                    diff.push_back(abs(j-i));
                    else
                        diff.push_back(n - abs(j-i));
                }
            }
        }
        int x = diff[0];
        for(auto it: diff){
            cout<<it<<" ";
            if(it != x) return -1;
        }
        return x;
    }
};
