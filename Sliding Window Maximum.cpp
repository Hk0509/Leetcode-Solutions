class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        for(int i=0; i<k; i++){
            pq.push({nums[i], i});
        }

        for(int i = k; i<n; i++){
            ans.push_back(pq.top().first);
            while(i - pq.top().second >= k && pq.size()>0){
                pq.pop();
            }
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);

        return ans;
    }
};
