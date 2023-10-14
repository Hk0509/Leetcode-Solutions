class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, bloom; 
        int n = flowers.size();

        for (auto it : flowers) {
            start.push_back(it[0]);
            bloom.push_back(it[1]);
        }

        sort(start.begin(), start.end());
        sort(bloom.begin(), bloom.end());

        vector<int> result;

        for (int i = 0; i < people.size(); i++) {
            int before = start.size() - (upper_bound(start.begin(), start.end(), people[i]) - start.begin());

            int after = bloom.size() - (lower_bound(bloom.begin(), bloom.end(), people[i]) - bloom.begin());

            result.push_back(after - before);
        }

        return result; 
    }
};
