class Solution {
public:
    bool makeEqual(vector<string>& words) { 
        int n = words.size();
        unordered_map<char, int> mpp;
        for(int i=0; i<n; i++){
            for(auto ch: words[i]){
                mpp[ch]++;
            }
        }

        for(auto it: mpp){
            if(it.second % n != 0) return 0;
        }

        return 1;
    }
};
