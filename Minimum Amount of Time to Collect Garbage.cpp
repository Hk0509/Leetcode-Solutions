class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int time = 0;
        bool flagG = 0, flagP = 0, flagM = 0; 
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<garbage[i].size(); j++){
                if(garbage[i][j] == 'G'){
                    flagG = 1;
                    time++;
                }
                if(garbage[i][j] == 'M'){
                    flagM = 1;
                    time++;
                }
                if(garbage[i][j] == 'P'){
                    flagP = 1;
                    time++;
                }
            }
            if(i!= 0 && flagG) time += travel[i-1];
            if(i!= 0 && flagP) time += travel[i-1];
            if(i!= 0 && flagM) time += travel[i-1];
        }
        return time;
    }
};
