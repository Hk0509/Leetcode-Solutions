class Solution {
public:       
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A){
        int n = A.size();
        vector<int> left(n), right(n);
        
        stack<int>st;
        st.push(0);
        left[0] = 1; 
        for(int i=1; i<n; i++)
        {
            while(!st.empty() && A[i] < A[st.top()]) 
                st.pop();
            
            if(st.empty()) 
                left[i] = i+1; 
            else 
                left[i] = i - st.top(); 
            
            st.push(i);
            
        }
        
        while(st.size()) 
            st.pop();
    
        st.push(n-1);
        right[n-1] = 1;
        for(int i=n-2; i>=0; i--)
        {
            while(!st.empty() && A[i] <= A[st.top()]) 
                st.pop();
            
            if(st.empty()) 
                right[i] = n-i; 
            else 
                right[i] = st.top()-i;
            
            st.push(i);
        }
        
        // for(int i=0; i<n; i++) 
        //      cout << left[i] << " : " << right[i] << endl;
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            long long pro = (left[i]*right[i])%MOD;
            pro = (pro*A[i])%MOD;
            ans = (ans + pro)%MOD;
        }
        
        return ans%MOD;
    }
    
};
