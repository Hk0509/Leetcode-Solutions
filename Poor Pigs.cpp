class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int trials = minutesToTest/minutesToDie;
        int pigs = ceil(log2(buckets)/log2(trials+1));

        return pigs;
    }
};
