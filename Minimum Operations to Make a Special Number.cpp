class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        if(n == 1) return 1;
        int mini = 1e8;
        int ind1 = -1, ind2 = -1;
        for(int i=n-1; i>0; i--){
            for(int j=i-1; j>=0; j--){
                if(num[j] == '0' && num[i] == '0'){
                    int count = n - i - 1;
                    count += abs(j - i) - 1;
                    if(count < mini){
                        mini = count;
                        ind1 = j, ind2 = i; 
                        
                    } 
                }
                if(num[j] == '2' && num[i] == '5'){
                    int count = n - i - 1;
                    count += abs(j - i) - 1;
                    if(count < mini){
                        mini = count;
                        ind1 = j, ind2 = i; 
                    }
                }
                if(num[j] == '7' && num[i] == '5'){
                    int count = n - i - 1;
                    count += abs(j - i) - 1;
                    if(count < mini){
                        mini = count;
                        ind1 = j, ind2 = i; 
                    }
                }
                if(num[j] == '5' && num[i] == '0'){
                    int count = n - i - 1;
                    count += abs(j - i) - 1;
                    if(count < mini){
                        mini = count;
                        ind1 = j, ind2 = i; 
                    }
                }
            }
        }
        bool flag = 0;
        for(auto it: num){
            if(it == '0'){
                flag = 1;
                break;   
            }
        }
 
        int count = n - ind2 - 1;
        count += abs(ind1 - ind2) - 1;
        
        if(ind1 == -1 || ind2 == -1){
            if(flag)
            return n - 1;
            else
            return n;
        }
    
        return count;
    }
};
