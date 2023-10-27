class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,long long int> mpp;
        sort(begin(arr) , end(arr));

        for(int i = 0 ; i < n ; i++){
            mpp[arr[i]] = 1;
        }

        for(int i =  1 ; i < n ; i++){
            int root = arr[i];
            for(int j = 0 ; j < i ; j++){
                int left = arr[j];
                if(root % left == 0){   
                    int right = root/left;
                    if(mpp.find(right) != mpp.end()){
                        mpp[root] += mpp[left] * mpp[right];
                    }
                }
            }
        }

        int sum = 0;
        for(auto it : mpp){
           sum = (sum + it.second)%mod;

        }
        return sum;
    }
};
