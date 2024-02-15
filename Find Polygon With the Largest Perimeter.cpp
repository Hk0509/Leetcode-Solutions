//POTD
#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      ll sum = 0, n = nums.size(), ans = 0;
      for(int i=0; i<n-1; i++){
        sum += nums[i];
        if(sum > nums[i+1]){
            ans = sum + nums[i+1];
        }
      }  
      if(ans == 0) return -1;
      return ans;
    }
};



// Contest
// class Solution {
// public:
//     long long largestPerimeter(vector<int>& nums){
//         sort(nums.begin(),nums.end());
//         long long ans = 0, sum = nums[0];
//         int n = nums.size();
        
//         for(int i=1; i<n; i++){
//             if(sum > nums[i]){
//                 ans = sum + nums[i];
//             }
//             sum += nums[i];
//         }
        
//         return ans == 0 ? -1 : ans;
        
//     }
// };
