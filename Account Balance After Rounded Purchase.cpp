class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int balance = purchaseAmount%10;
        if(balance >= 5)
        purchaseAmount += (10 - balance);
        else 
        purchaseAmount -= balance;
        return (100 - purchaseAmount);
    }
};
