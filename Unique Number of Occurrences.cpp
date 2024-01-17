class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp1, mpp2;
        for (auto it : arr) {
            mpp1[it]++;
        }

        for (auto it : mpp1) {
            mpp2[it.second]++;
            if (mpp2[it.second] > 1)
                return 0;
        }

        return 1;
    }
};
