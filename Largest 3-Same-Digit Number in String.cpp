class Solution {
public:
    string largestGoodInteger(string num) {
       int dig = -1, n = num.size();
       for(int i=2; i<n; ++i){
           if(num[i] == num[i-1] && num[i-1] == num[i-2]){
                if(num[i] - '0' > dig){
                    dig = num[i] - '0';
                }
           }
       }

       string ans;
       if(dig == -1)   
        ans = "";
       else if(dig == 0) 
        ans = "000";
       else
        ans = to_string(dig*100 + dig * 10 + dig);
       
       return ans;
    }
};
