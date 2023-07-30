class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<pair<char, int>> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') st.push({'(', i});
            else if(!st.empty() && st.top().first == '(' && s[i] == ')') st.pop();
            else if(s[i] == ')') st.push({')', i});
        }

        while(!st.empty()){
            s[st.top().second] = '0';
            st.pop();
        }

        for(int i=0; i<s.size(); i++){
            if(s[i] != '0') ans+=s[i];
        }

        return ans;
    }   
};
