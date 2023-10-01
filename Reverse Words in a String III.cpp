class Solution {
public:
    string reverseWords(string s) {
        string temp, ans;
        for(auto it: s){
            if(it == ' '){
                reverse(temp.begin(), temp.end());
                temp += " ";
                ans+=temp;
                temp.clear();
            }
            else{
                temp+=it;
            }
        }
        reverse(temp.begin(), temp.end());
        ans+=temp;
        return ans;
    }
};
