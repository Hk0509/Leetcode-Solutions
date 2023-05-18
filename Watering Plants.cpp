class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int count = 0, n = plants.size(), refill = capacity, steps = 0;
        for(int i=0; i<n; i++)
        {
            if(capacity<plants[i])
            {
                steps += 2*i;
                capacity = refill;
            }

            steps++;
            capacity -= plants[i];
        }
        return steps;
    }
};
