class Solution {
public:
    bool isFascinating(int n) {
        string str = to_string(n) + to_string(2*n) + to_string(3*n);
        int arr[9] = {0};
   
        if(str.size() != 9) return 0;
        
        for(int i=0; i<str.size(); i++)
        {
            if(str[i] - '0' < 1 || str[i] - '0' > 9) return 0;
            if(arr[(str[i] - '0') - 1] != -1)
            arr[(str[i] - '0') - 1] = -1;
            else
                return 0;
        }        
        return 1;
    }
};
