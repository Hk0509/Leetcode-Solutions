class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        if(costs[0] > coins) return 0;

        for(int i=1; i<costs.size(); i++)
        {
            costs[i] += costs[i-1];
            if(costs[i] > coins) return i;
            else if(costs[i] == coins) return i+1;
        }
        return costs.size();
    }
};
