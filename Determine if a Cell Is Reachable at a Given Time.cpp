class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(fx - sx);
        int y = abs(fy - sy);
        
        int maxDiff = max(x,y);
        if(!x && !y){
            return(!(t==1));
        }
        return (maxDiff <= t);
    }
};
