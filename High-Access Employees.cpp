class Solution {
public:
    bool checkIfUnderHour(int time1, int time2){
        int hours1 = time1 / 100;
        int minutes1 = time1 % 100;

        int hours2 = time2 / 100;
        int minutes2 = time2 % 100;

        int totalMinutes1 = hours1 * 60 + minutes1;
        int totalMinutes2 = hours2 * 60 + minutes2;


        int difference = abs(totalMinutes1 - totalMinutes2);

        if (difference < 60) {
           return true;
        } else {
            return false;
        }
    }
    
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> hash;
        
        for(auto it : access_times){
            hash[it[0]].push_back(stoi(it[1]));
        }
    
        
        vector<string> ans;
        
        for(auto it : hash){
            if(it.second.size() >= 3){
                auto times = it.second;
                
                sort(times.begin(), times.end());
                
                for(int i = 0; i<times.size()-2; i++){
                    
                    if(checkIfUnderHour(times[i], times[i+2])){
                        ans.push_back(it.first);
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};
