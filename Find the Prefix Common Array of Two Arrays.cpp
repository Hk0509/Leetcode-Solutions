class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> C;
        map<int, int> mpp;
        int count = 0;
        for(int i=0; i<A.size(); i++)
        {
            count = 0;
            mpp[A[i]]++;
            for(int j=0; j<=i; j++)
            {
                if(mpp[B[j]]>=1)
                    count++;
            }
            C.push_back(count);
        }
        return C;
    }
};
