class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int count0 = 0, count1 = 0, n =derived.size();
        for(int i=0; i<n; i++)
        {
            if(derived[i] == 0) count0++;
            else count1++;
        }
        if(count1 % 2 == 0 && n % 2 != 0 || (count0 % 2 == 0 && n % 2 == 0))
        return true;
        else 
        return false;
    }
};
