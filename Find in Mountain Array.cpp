/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findAns(int s, int e, MountainArray &mountainArr, int target, bool isInc){
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int midValue = mountainArr.get(mid);
            if(midValue == target){
                ans = mid;
                e = mid - 1;
            }
            else if(isInc){
                if(midValue < target)
                    s = mid+1;
                else
                    e = mid-1;
            }
            else{
                if(midValue > target)
                    s = mid+1;
                else
                    e = mid-1;
            }
        }
        return ans;
    }

    int findPeak(int s, int e, MountainArray &mountainArr, int target){
        int peak = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int midValue = mountainArr.get(mid);
            if(midValue>mountainArr.get(mid+1) && midValue>mountainArr.get(mid-1)){
                peak = mid;
                break;
            }
            else if(midValue < mountainArr.get(mid+1)){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return peak;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int s = 0, e = n-1;

        int peak = findPeak(0, n-1, mountainArr, target);

        int ans = findAns(0, peak-1, mountainArr, target, 1);
        ans = (ans == -1) ? findAns(peak, n-1, mountainArr, target, 0) : ans;

        return ans;
    }
};
