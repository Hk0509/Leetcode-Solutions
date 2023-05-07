class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int defecit = 0;
        int balance = 0;
        for(int i=0; i<gas.size(); i++)
        {
            balance += gas[i] - cost[i];
            if(balance < 0)
            {   
                start = i+1;
                defecit += balance;
                balance = 0;
            }
        }
        if((balance + defecit) < 0) return -1;
        else return start;
    }
};
