class Solution {
private:
    bool check(string a){
        int x = a.size();
        int sum1 = 0, sum2 = 0;
        for(int i=0; i<x/2; i++){
            sum1 += a[i] - '0';
            sum2 += a[i+x/2] - '0';
        }
        return sum1 == sum2;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i<=high; i++){
            string temp = to_string(i);
            if(temp.size()%2 == 0){
               if (check(temp))cnt++;
            }
        }
        return cnt;
    }
};
