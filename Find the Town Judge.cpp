class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n+1, 0);
        vector<int> outDegree(n+1, 0);

        for(auto it: trust){
            inDegree[it[0]]++;
            outDegree[it[1]]++;
        }

        for(int i=1; i<=n; i++){
            if(inDegree[i] == 0 && outDegree[i] == n-1) return i;
        }

        return -1;
    }
};
