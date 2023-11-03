class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int pushCount = n;
        int popCount = n - target.size();
        int currInt = 1;
        int currInd = 0;
        for(int i=0; i<pushCount + popCount; i++){
            if(currInt == target[currInd]){
                ans.push_back("Push"); 
                currInd++;
            }
            else{
                ans.push_back("Push"); 
                ans.push_back("Pop"); 
            }
            currInt++;
            if(currInt > target[target.size()-1]) break;
        }
        return ans;
    }
};
