class comp{
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        if(a.first > b.first) return true;
        if(a.first == b.first) return (a.second < b.second);
        return false;
    }
};

class Solution {
private:
    void makeVector(string& report, vector<string>& words){
        int n = report.size();
        string word;
        for(auto it: report){ 
            if(it == ' '){
                words.push_back(word);
                word = "";
            }
            else{
                word += it;
            }
        }
        if(!word.empty()) words.push_back(word);
    }
public:
    vector<int> topStudents(vector<string>& pos, vector<string>& neg, vector<string>& report, vector<int>& sid, int k) {
        unordered_set<string> pf, nf;
        for(auto it: pos) pf.insert(it);
        for(auto it: neg) nf.insert(it);

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        int n = report.size();

        for(int i=0; i<n; i++){
            vector<string> words;
            makeVector(report[i], words);

            int cnt = 0;
            for(auto it: words){
                if(pf.find(it) != pf.end()){
                    cnt += 3;
                }
                else if(nf.find(it) != nf.end()){
                    cnt -= 1;
                }
            }
            pq.push({cnt, sid[i]});
            if(!pq.empty() && i>=k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(k--){
            int stud = pq.top().second;
            pq.pop();
            ans.push_back(stud);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
