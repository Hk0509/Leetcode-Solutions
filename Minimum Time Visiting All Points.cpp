class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for(int i = 1; i<n; i++){
            int x = abs(points[i][0] - points[i-1][0]);
            int y = abs(points[i][1] - points[i-1][1]);
            ans += max(x, y);
        }
        return ans;
    }
};
