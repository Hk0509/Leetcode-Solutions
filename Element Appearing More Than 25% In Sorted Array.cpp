class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]) cnt++;
            else cnt = 1;
            if(cnt > n/4) return arr[i];
        }
        return arr[0];
    }
};
