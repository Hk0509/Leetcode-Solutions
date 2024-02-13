class Solution {
public:
    bool isPalin(string &str){
        int s = 0, e = str.size()-1;
        while(s<e){
            if(str[s++] != str[e--]) return 0;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(int i=0; i<n; i++){
            if(isPalin(words[i])) return words[i];
        }
        return "";
    }
};
