class Solution {
public:

    void rotateArr(vector<int>& nums, int start, int end)
    {
        while(start < end)
        {
            swap(nums[start++],nums[end--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) k = k%n;
        rotateArr(nums, 0, n-k-1);
        rotateArr(nums, n-k, n-1);
        rotateArr(nums, 0, n-1);
    }
};
