class Solution {
public:
    int countCharacters(vector<string>& words, string chars){
        map<char, int> mpp, mpp2;
        for(auto chr: chars) mpp[chr]++;
        mpp2 = mpp;
        int ans = 0;

        for(auto wrd: words){
            mpp = mpp2;
            bool good = true;

            for(auto chr: wrd){
                if(mpp[chr]<=0){
                    good = false;
                    break;
                }
                else{
                    mpp[chr]--;
                }
            }

            if(good) ans += wrd.size();
        }

        return ans;
    }
};
