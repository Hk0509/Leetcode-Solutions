class Solution {
public:
    string sortVowels(string s) {
        string temp;
        for(auto it: s){
            if(it == 'a' || it == 'e' || it =='i' || it == 'o' || it == 'u' || 
             it == 'A' || it == 'E' || it =='I' || it == 'O' || it == 'U'){
                temp.push_back(it);
            }
        }
        sort(temp.begin(), temp.end());
        int i = 0;
        for(auto& it: s){
            if(it == 'a' || it == 'e' || it =='i' || it == 'o' || it == 'u' || 
             it == 'A' || it == 'E' || it =='I' || it == 'O' || it == 'U'){
                it = temp[i++];
            }
        }
        return s;
    }
};
