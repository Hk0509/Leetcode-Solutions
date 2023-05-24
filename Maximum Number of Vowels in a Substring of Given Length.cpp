class Solution {
public:
    int maxVowels(string s, int k) {
       int count = 0, max = INT_MIN, j=-1;
       
       for(int i = 0; i<s.length(); i++)
       {
            if(i>=k)
            j++;

            if(j>=0 && (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'))
            count--;

           if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
           count++;

           if(count>max) max = count;

           if(max>k) break;
       }
       return max;
    }
};
