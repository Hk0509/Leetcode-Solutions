class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end(), greater<int>());
        int ans = 0;
        for(int i=1; i<n; i+=2){
            ans += piles[i];
            n = n-1;
        }
        return ans;
    }
};
