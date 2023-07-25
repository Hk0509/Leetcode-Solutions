class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        int n = words.size();
        vector<string> ans;
        for(int i=0; i<n; i++){
            bool flag = 0;
            string temp;
            for(int j=0; j<words[i].size(); j++){
                if(words[i][j] != separator){
                    flag = 1;
                    temp+=words[i][j];
                }
                if((words[i][j] == separator || j==words[i].size()-1) && flag){
                    ans.push_back(temp);
                    temp.clear();
                    flag = 0;
                }
            }
        }
        return ans;
    }
};
