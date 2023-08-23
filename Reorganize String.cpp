class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        for(auto it: s){
            mpp[it]++;
            if(mpp[it] > (n/2 + n%2)) return "";
        }

        priority_queue<pair<int, char>> pq;
        for(auto it: mpp){
            pq.push({it.second, it.first});
        }
        
        int i=0;
        while(!pq.empty()){
            int freq = pq.top().first;
            int ch = pq.top().second;
            while(freq--){
                if(i >= n) i = 1;
                s[i] = ch;
                i+=2;
            }
            pq.pop();
        }

        return s;
    }
};
