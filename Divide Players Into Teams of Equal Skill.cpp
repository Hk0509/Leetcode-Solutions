class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int n = skill.size(), j = n-2;
        int prev = skill[0] + skill[n-1];
        long long chem  = skill[0] * skill[n-1];

        for(int i=1; i<n/2; i++)
        {
            if(skill[i] + skill[j] != prev) return -1;
            chem = chem + (skill[i] * skill[j--]); 
        }
        return chem;
    }
};
