class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<string> temp = strs;
    vector<vector<string>>ans;
    for(int i=0; i<strs.size(); i++) 
    {
        sort(strs[i].begin(), strs[i].end()); 
    }
    for(int i=0; i<strs.size(); i++) 
    {
        vector<string>words;
        for(int j=0; j<strs.size(); j++) 
        {
            if(strs[i] == strs[j]) 
            words.push_back(temp[j]); 
        }
        ans.push_back(words);
    }
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=i+1; j<ans.size(); j++)
        {
            if(ans[i] == ans[j])
            {
                ans.erase(ans.begin()+j);
                j--;
            }
        }
    }
    return ans;
    }
};
