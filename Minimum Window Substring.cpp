class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char, int> mpp;

        int ans = 1e9, start = 0;
        for(auto it : t) mpp[it]++;

        int count = mpp.size(), i=0, j=0;

        while(j < s.length()){
            mpp[s[j]]--;
            if(mpp[s[j]] == 0)
                count--;

            if(count == 0) {
                while(count == 0){
                    if(ans > j - i + 1){
                        ans = j - i + 1;
                        start = i;
                    }
                    mpp[s[i]]++;
                    if(mpp[s[i]] > 0) count++;
                    i++;
                }
            }
            j++;
        }
        return ans == 1e9 ? "" : s.substr(start, ans);
    }
};
