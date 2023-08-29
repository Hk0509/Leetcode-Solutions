class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = 0;
        for(auto it: customers){
            if(it == 'N') penalty++;
        }

        int index = n;
        int minPen = penalty;
        for(int i=n-1; i>=0; i--){
            if(customers[i] == 'Y'){
                penalty++;
            }
            else{
                penalty--;
            }
            if(penalty <= minPen){
                index = i;
                minPen = penalty;
            }
        }

        return index;
    }
};
