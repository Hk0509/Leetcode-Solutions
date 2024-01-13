class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26] = {0};
        for(auto it: s){
            freq[it - 'a']++;
        }
        
        for(auto it: t){
            freq[it - 'a']--;
        }

        int ans = 0;
        for(int i=0; i<26; i++){
            ans += abs(freq[i]);
        }
 
        return ans/2;
    }
};
