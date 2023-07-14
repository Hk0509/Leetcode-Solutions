class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mpp;
        int len = 1;
        for(int i=0; i<arr.size(); i++){
            mpp[arr[i]] = 1 + mpp[arr[i] - difference];
            len = max(len, mpp[arr[i]]);
        }
        return len;
    }
};
