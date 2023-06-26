class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> start,end;
        int i = 0, j = costs.size()-1;
        int count = 0;
        long long ans = 0;
        while(count<k)
        {
            while(start.size() < candidates && i<=j) start.push(costs[i++]);
            while(end.size() < candidates && j>=i) end.push(costs[j--]);

            int front = 1e9,back = 1e9;
            if(start.size() > 0) front = start.top();
            if(end.size() > 0) back = end.top();
            if(front<=back)
            {
                ans += front;
                start.pop();
            } 
            else 
            {
                ans += back;
                end.pop();
            }
            count++;
        }
        return ans;
    }
};
