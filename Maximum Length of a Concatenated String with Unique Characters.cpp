class Solution {
public:
    void solve(int n, string& temp, int& ans, vector<string>& arr){
        if(n < 0){
            vector<int> freq(26, 0);
            bool flag = 0;
            for(auto it: temp){
                freq[it - 'a']++;
                if(freq[it - 'a'] > 1){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                int x = temp.size();
                ans = max(ans, x);
            }
            return ;
        }

        temp += arr[n];
        solve(n-1, temp, ans, arr);
        if(!temp.empty())
        for(int i=0; i<arr[n].size(); i++){
            temp.pop_back();
        }
        solve(n-1, temp, ans, arr);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp;
        int ans = 0;
        solve(n-1, temp, ans, arr);
        return ans;
    }
};
