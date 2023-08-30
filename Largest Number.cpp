class Solution {
private:
    static bool comp(string& a, string& b){
        return a+b > b+a;    
    }

    void trim(string& a){
        int i = 0;
        while(i<a.size()-1 && a[i] == '0'){
            a.erase(a.begin() + i);
        }
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums2;
        for(auto it: nums){
            nums2.push_back(to_string(it));
        }

        sort(nums2.begin(), nums2.end(), comp);
        string ans;
        for(int i=0; i<nums2.size(); i++){
            for(auto jt: nums2[i]){
                ans+=jt;
            }
        }
        trim(ans);
        return ans;
    }
};
