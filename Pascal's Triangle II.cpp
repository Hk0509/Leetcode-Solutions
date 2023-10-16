class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        long long prev = 1;
        row.push_back(1);
        for(int i=0; i<rowIndex; i++){
            long long nCr = prev*(rowIndex-i)/(i+1);
            row.push_back(nCr);
            prev = nCr;
        }
        return row;
    }
};
