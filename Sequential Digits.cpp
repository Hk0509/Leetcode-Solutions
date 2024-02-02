class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string map = "123456789";
        vector<int> ans;

        int mini = to_string(low).size();
        int maxi = to_string(high).size();

        for(int i = 0; i<9; i++){
            string temp;
            for(int j = i; j<9; j++){
                temp += map[j];
                int x = stoi(temp);
                if(x >= low && x <= high){
                    ans.push_back(x);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
