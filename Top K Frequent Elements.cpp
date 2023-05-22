class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       vector<int> ans;
       unordered_map<int, int>mpp;
       priority_queue<int> p;
       for(auto it:nums) mpp[it]++;
       for(auto it:mpp) p.push(it.second);
       while(!p.empty())
       {   
           if(k==0) break;
           for(auto jt:mpp)
           {
               if(jt.second == p.top()) 
               {
                  p.pop();
                  ans.push_back(jt.first);
                  mpp.erase(jt.first);
                  k--;
                  break;
               }
           }
       }
       return ans;
    }
};
