class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int maxi = INT_MIN;
        for(int i=1; i<n; i++){
            maxi = max(points[i][0] - points[i-1][0], maxi);
        }
        return maxi;
    }
};
