class Solution {
private:
    void trim(string& s, int n){
        int i = 0;
        while(i<n && s[i] == ' '){
            s.erase(s.begin() + i);
        }
        
        int e = n-1;
        while(e>=0 && s[e] == ' '){
            s.erase(s.begin() + e);
        }
    }
public:
    string reverseWords(string s) {
        int n = s.size();
        trim(s, n);
        bool firstSpace = 1;
        string temp = "", ans = "";
        reverse(s.begin(), s.end());
        int size = s.size();
        
        for(int i=0; i<size; i++){
            if(s[i] != ' ')
            temp+=s[i];
            else if(i!= 0 && s[i-1] != ' ' && s[i] == ' '){
                reverse(temp.begin(), temp.end());
                ans+=temp;
                ans+=' ';
                temp.clear();
            }
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};
