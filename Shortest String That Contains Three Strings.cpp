class Solution {
private:
    string check(string &a, string &b){
        if(a.find(b) != string :: npos) return a;
        
        for(int i=min(a.length(), b.length()); i>=0; i--){
            if(a.substr(a.length()-i) == b.substr(0, i)){
                return a + b.substr(i);
            }
        }
        return a+b;
    }

    void isValid(string &e, string& ans){
        if(ans == "" || e.size() < ans.size() || (e.size() == ans.size() && e<ans))
        ans = e;
    }

public:
    string minimumString(string a, string b, string c) {
        vector<string> v = {a, b, c};
        string ans = "";
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
                for(int k=0; k<v.size(); k++)
                {
                    if(i != j && j!=k && k!=i){
                        string a = v[i];
                        string b = v[j];
                        string c = v[k];
                        string d = check(a,b);
                        string e = check(d,c);
                       
                        isValid(e, ans);
                    }
                }
            }
        }
        return ans;
    }
};
