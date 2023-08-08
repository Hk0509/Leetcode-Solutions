class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid = high - (high - low)/2;
        while(low <= high){
            if(nums[mid] == target){
                return mid;
            }           
            else if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(target <= nums[high] && target >= nums[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            mid = high - (high - low)/2;
        }
        return -1;
    }
};
