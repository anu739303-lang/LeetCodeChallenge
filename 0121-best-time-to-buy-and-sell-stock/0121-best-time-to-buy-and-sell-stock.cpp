class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int mnStockPrice = prices[0];
        for (int i = 1; i < n; i++){
            profit = max(profit,prices[i] - mnStockPrice);
            mnStockPrice = min(mnStockPrice,prices[i]);

        }
        return profit;
    }
};