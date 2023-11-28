class Solution {
public:
    const int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        vector<int> num;
        for(int i = 0; i < corridor.size(); i++) {
            if(corridor[i] == 'S'){
                num.push_back(i);
            }
        }

        if(num.size() % 2 != 0 || num.size() == 0) return 0;

        int result = 1;
        for(int i = 2; i<num.size(); i+=2) {
            result = (result * 1ll *  (num[i] - num[i-1])) % mod;
        }
        
        return result;
    }
};
