class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        ans.push_back(pref[0]);
        for(int i=1; i<pref.size(); i++)
        {
            int x = pref[i-1] ^ pref[i];
            ans.push_back(x);
        }
        return ans;
    }
};
