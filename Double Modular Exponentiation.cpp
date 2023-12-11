class Solution {
public:
    int power(int x, int y, int p) { 
        int ans = 1;
        while(y > 0){ 
           ans = (ans * x) % p;
           y--;
        } 
        return ans; 
} 
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for(int i = 0; i< variables.size(); i++){
             int a = variables[i][0];
             int b = variables[i][1];
             int c = variables[i][2];
             int m = variables[i][3];
             int first = power(a, b, 10);
             int val = power(first, c, m);;
            if(val == target) ans.push_back(i);
        }
        return ans;
    }
};
