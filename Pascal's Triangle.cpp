class Solution {
public:
    vector<int> generateRow(int r){
        long long prev = 1;
        vector<int> row;
        row.push_back(1);
        for(int i=0; i<r; i++){
            long long nCr = prev*(r-i)/(i+1);
            row.push_back(nCr);
            prev = nCr;
        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
