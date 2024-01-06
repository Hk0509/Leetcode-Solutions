class Solution {
public:
    int maximumLength(string s) {
         int n = s.size(), cnt = -1;
        unordered_map<pair<char, int>, int, hash<pair<char, int>>> mpp;
         int prev = s[0], len = 1;
          mpp[{s[0], 1}]++;
         for(int i=1; i<n; i++){
             if(s[i] == s[i-1]) len++;
             else{
              len = 1;
              prev = s[i];
             }
             mpp[{s[i], len}]++;
         }
        
       for (auto it = mpp.rbegin(); it != mpp.rend(); ++it) {
        char currentChar = it->first.first;
        int currentInt = it->first.second;

        auto nextIt = next(it);
        if (nextIt != mpp.rend()) {
            char nextChar = nextIt->first.first;
            int nextInt = nextIt->first.second;

            if (currentChar == nextChar && currentInt > nextInt) {
                mpp[{nextChar, nextInt}] += it->second;
            }
        }
    }

        for(auto it: mpp){
            if(it.second >= 3) cnt = max(cnt, it.first.second);
        }
         return cnt == 0? -1: cnt;
    }
};
