class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long sum = 0;
        int count = 0;
        for(int i=1; i<=target/2; i++){
            sum+=i;
            count++;
            if(count == n) break;
        }

        int i = target;
        while(count<n){
            sum += (i++);
            count++;
        }

        return sum;
    }
};

// class Solution {
// public:
//     long long minimumPossibleSum(int n, int target) {
//         unordered_set<int> st;
//         long long sum = 0;
//         int i=1;
//         while(st.size()<n){
//             if(st.find(target - i) == st.end()){
//                 st.insert(i);
//                 sum += i;
//             }
//             i++;
//         }
//         return sum;
//     }
// };
