class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a, b;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '#'){
               if(!a.empty())
               a.pop();
            }
            else{
                a.push(s[i]);
            }
        }

        for(int i=0; i<t.size(); i++){
            if(t[i] == '#'){
                if(!b.empty())
                b.pop();
            }
            else{
                b.push(t[i]);
            }
        }

        string s1, s2;
        while(!a.empty()){
            s1+=a.top();
            a.pop();
        }
        while(!b.empty()){
            s2+=b.top();
            b.pop();
        }
        
        return s1 == s2;
    }
};
