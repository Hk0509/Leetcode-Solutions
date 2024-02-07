class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        string ans;
        for(auto it: s) mpp[it]++;
        priority_queue<pair<int, char>> pq;
        for(auto it: mpp){
            pq.push({it.second, it.first});
        }

        while(!pq.empty()){
            pair<int, char> temp = pq.top();
            pq.pop();
            while(temp.first--) ans+=temp.second;
        }

        return ans;
    }
};
