class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int count = 0;
        int currA = capacityA;
        int currB = capacityB;
        int n = plants.size(), s = 0, e = n-1;
        while(s<e)
        {
            if(plants[s] > currA)
            {
                currA = capacityA;
                count++;
            }
            currA -= plants[s++];

            if(plants[e] > currB)
            {
                currB = capacityB;
                count++;
            }
            currB -= plants[e--];
        }
        if(s == e)
        {
            if(plants[s]>currA && plants[s]>currB)
            count++;
        }
        return count;

    }
};
