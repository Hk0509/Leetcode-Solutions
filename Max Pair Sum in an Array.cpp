class Solution {
private:
    int maxDig(string a){
        int maxi = -1e8;
        for(int i=0; i<a.size(); i++){
            maxi = max(maxi, a[i] - '0');
        }
        return maxi;
    }
public:
    int maxi = -1e8;
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                string a = to_string(nums[i]);
                string b = to_string(nums[j]);
                if(maxDig(a) == maxDig(b)){
                    maxi = max(nums[i] + nums[j], maxi);
                }
            }
        }
    if(maxi == -1e8) return -1;
    return maxi;
    }
};
