class Solution {
private:
    int findSoldierCount(int s, int e, vector<int>& row){
        while(s<=e){
            int mid = e - (e-s)/2;
            if(row[mid]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return s;
    }

    void getAns(priority_queue<pair<int,int>>& pq, vector<int>& ans){
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
    }

    void findWeakest(vector<vector<int>>& mat, int k, int n , int m, priority_queue<pair<int, int>>& pq){
        for(int i=0; i<n; i++){
            int count = findSoldierCount(0, m-1, mat[i]);
            pq.push({count, i});
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int, int>> pq;
        findWeakest(mat, k, n, m, pq);
        vector<int> ans;
        getAns(pq, ans);
        return ans;
    }
};
