class Solution {
public:
    //Custom comparator for priority_queue, it checks the sum of pair of elements and arrange accordingly 
    class Compare{
    public:
        bool operator()(pair<int, int> a, pair<int, int> b){
            if((a.first + a.second) < (b.first + b.second)) return true;
            return false;

        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    int m = nums2.size();
    //Initializing custom priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; 
    vector<vector<int>> ans;

    int count = 0;
    for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++) {
                int sum = 0; 

                if(count<k) {
                    pq.push(make_pair(nums1[i], nums2[j]));
                    count++;
                }
                else {
                    sum += nums1[i] + nums2[j];

                    if(!pq.empty() && (sum < pq.top().first + pq.top().second)){
                    pq.pop();
                    pq.push(make_pair(nums1[i], nums2[j]));
                    }
                    else break;
                }
            }
        }

    while(!pq.empty()){
        ans.push_back({pq.top().first, pq.top().second});
        pq.pop();
    }

    return ans;
    }
};
