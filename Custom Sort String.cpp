class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mpp;
        string ans;
        
        for(int i=0; i<s.size(); i++)
        {
            mpp[s[i]]++;
        }

        int j = 0;
        for(int i=0; i<order.size(); i++)
        {
           while(mpp[order[i]]--)ans += order[i];
           mpp[order[i]] = 0;
        }

        for(auto it: mpp)
        {
            while(it.second>0)
            {
                ans+=it.first;
                it.second--;
            }
            if(ans.size()==s.size()) break;
        }

        return ans;
    }
};
