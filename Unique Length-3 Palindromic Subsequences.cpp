class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>left(26);
        vector<int>right(26);
        unordered_set<string>st;
    
        for(int i = 0; i<s.size(); i++){
            right[s[i]-'a']++;
        }

        for(int i = 0 ; i<s.size();i++){
            right[s[i]-'a']--;
            for(int j = 0; j<26;j++){
                if(left[j]>0 && right[j]>0){
                    char x = 'a' + j; 
                    string pali = "";
                    pali+=x;
                    pali+=s[i];
                    pali+=x;    
                    
                    if(st.count(pali)){
                        continue;
                    }  
                    st.insert(pali);
                }
            }
            left[s[i]-'a']++;
        }
        return st.size();
    }
};
