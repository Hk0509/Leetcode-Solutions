class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto &it: tokens){
            if(it =="+" || it =="-" || it =="*" || it =="/"){
                long long first = st.top(); 
                st.pop();
                long long second = st.top(); 
                st.pop();
                if(it == "+")
                    first = second + first;
                if(it == "-") 
                    first = second - first;
                if(it == "*") 
                    first = second * first;
                if(it == "/") 
                    first = second / first;
                st.push(first);
            }
            else st.push(stoi(it));
        }
        return st.top();
    }
};
