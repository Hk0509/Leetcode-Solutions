class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> time;
        for(int i=0; i<dist.size(); i++){
            float t = dist[i]/(float)speed[i];
            time.push_back(t);
        }

        sort(time.begin(), time.end());
        
        if(time[0] == 0) return 1;
        int ans = 1;
        for(int i=1; i<time.size(); i++){
            if(time[i] > i){
                ans++;
            }
            else break;
        }

        return ans;
    }
};
