class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int end = n*m-1;
        int start = 0;

        while(start<=end)
        {
            int mid = start + (end - start) / 2;
            if(matrix[mid/m][mid%m] == target)
            return 1;

            else if(matrix[mid/m][mid%m] < target)
            start = mid + 1;

            else
            end = mid - 1;
        }
        return 0;

    }
};
