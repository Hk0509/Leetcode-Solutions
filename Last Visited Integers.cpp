class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int n = words.size();
        vector<int> ans;
        vector<string> nums;
        for(int i=0; i<n; i++){
            if(words[i] != "prev")
            nums.push_back(words[i]);
            int j = nums.size()-1;
            while(i<=n-1 && words[i] == "prev"){
                if(j<0) ans.push_back(-1);
                else
                 ans.push_back(stoi(nums[j]));
                 i++;
                j--;
            }
            if(j != nums.size()-1) i--;
        }
        return ans;
    }
};
