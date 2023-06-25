class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int count = 0;
        for(int i=0; i<words.size(); i++){
            for(int j = i+1; j<words.size(); j++){
                 bool flag = 1;
                for(int k = 0; k<words[i].size(); k++){
                    if(words[i].size() != words[j].size() || words[i][k] != words[j][words[j].size()-k-1])
                        flag = 0;
                }
                if(flag == 1) count++;
            }
        }
        return count;
    }
};
