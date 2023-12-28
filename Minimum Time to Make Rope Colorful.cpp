class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        if (n == 1)
            return 0;
        int i = 0, j = 1;
        int ans = 0;
        while (i < n && j < n) {
            if (colors[i] != colors[j]) {
                i = j;
                j++;
            }
            if (colors[i] == colors[j]) {
                if (neededTime[i] >= neededTime[j]) {
                    ans += neededTime[j];
                    j++;
                } else {
                    ans += neededTime[i];
                    i = j + 1;
                }

                if (i > j)
                    swap(i, j);
            }
        }
        return ans;
    }
};
