class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        while(1){
            bool flag = 0;
            for(int i=0; i<nums.size()-1; i++){
                if(nums[i] > nums[i+1]){
                    if(__builtin_popcount(nums[i]) == __builtin_popcount(nums[i+1])){
                        swap(nums[i], nums[i+1]);
                        flag = 1;
                    }
                }
            }
             if(!flag) break;
        }
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]) return 0;
        }
        return 1;
    }
};
