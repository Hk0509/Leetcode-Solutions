class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long ans = 0;
        ans = num/3;
        if(num%3 == 0) return {ans-1, ans, ans+1};
        return {};
    }
};
