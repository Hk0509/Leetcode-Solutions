class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi = -1e9;
        for(auto it: right) maxi = max(n - it, maxi);
        for(auto it: left) maxi = max(it, maxi);
        return maxi;
    }
};
