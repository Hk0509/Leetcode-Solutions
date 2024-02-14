// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> neg;
//         vector<int> pos;
//         vector<int> ans;
//         for(auto it: nums)
//         {
//             if(it>0) pos.push_back(it);
//             else neg.push_back(it);
//         }
//         for(int i=0; i<nums.size()/2; i++)
//         {
//             ans.push_back(pos[i]);
//             ans.push_back(neg[i]);
//         }
//         return ans;
//     }
// };


//Inplace
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> neg, pos;
        for(int i = 0; i < n; i++){
            if(nums[i] < 0) neg.push_back(nums[i]);
            else if(nums[i] > 0) pos.push_back(nums[i]);
        }

        int j = 0, k = 0;
        for(int i=0; i<n; i+=2){
            nums[i] = pos[j++];
            nums[i+1] = neg[k++];
        }
        return nums;
    }
};
