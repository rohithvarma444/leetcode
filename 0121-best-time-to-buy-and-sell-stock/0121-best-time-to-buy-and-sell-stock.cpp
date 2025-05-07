class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int currLow = prices[0];
        int n = prices.size();
        for(int i = 1; i < n; i++){
            currLow = min(currLow,prices[i]);
            profit = max(profit,prices[i] - currLow);
        }

        return profit;
    }
};