class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return 0;
        map<char, int> mpp1, mpp2;
        for(auto it: word1){
            mpp1[it]++;
        }
        for(auto it: word2){
            mpp2[it]++;
        }
        
        map<int, int> mpp3;

        for(auto it: mpp1){
            if(mpp2[it.first] == 0) return 0;
            mpp3[it.second]++;
        }
        for(auto it: mpp2){
            if(mpp1[it.first] == 0) return 0;
            mpp3[it.second]--;
        }

        for(auto it: mpp3){
            if(it.second != 0) return 0;   
        }
        
        return 1;
    }
};
