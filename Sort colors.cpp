class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low++], nums[mid++]);
            }

            else if(nums[mid] == 1){
                mid++;
            }

            else{
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int count0 = 0, count1 = 0, count2 = 0;
//         for(int i=0; i<nums.size(); i++)
//         {
//             if(nums[i] == 0)
//             count0++;
//             else if(nums[i] == 1)
//             count1++;
//             else
//             count2++;
//         }

//         for(int i=0 ;i<nums.size(); i++)
//         {
//             if(count0-- > 0)
//             nums[i] = 0;
//             else if(count1-- > 0)
//             nums[i] = 1;
//             else
//             nums[i] = 2;
//         }

//     }
// };
