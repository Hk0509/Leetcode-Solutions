class Solution {
public:
    int candy(vector<int>& ratings) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int n = ratings.size();
        for(int i=1; i<n; i++){
            mpp[i] += 1;
            if(ratings[i] > ratings[i-1]) mpp[i] = mpp[i-1] + 1;
        }
        int ans = 0;
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1] && mpp[i] <= mpp[i+1]) mpp[i]=mpp[i+1] + 1;
            ans += mpp[i];
        }
        ans += mpp[n-1]; 
        return ans;  
    }
};
