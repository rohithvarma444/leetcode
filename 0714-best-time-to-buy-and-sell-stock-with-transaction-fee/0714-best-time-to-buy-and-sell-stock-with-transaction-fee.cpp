class Solution {
public:
    int helper(vector<int> &prices,vector<vector<int>> &dp,int n,int idx,int bought,int fee){
        if(idx == n) return 0;

        if(dp[idx][bought] != -1) return dp[idx][bought];

        int buy = 0;
        int sell = 0;
        int notBuy = helper(prices,dp,n,idx+1,bought,fee);
        if(bought == 0){
            buy = -prices[idx] + helper(prices,dp,n,idx+1,1,fee);
        }
        if(bought == 1){
            sell = prices[idx] - fee + helper(prices,dp,n,idx+1,0,fee);
        }
        return dp[idx][bought] = max(buy, max(notBuy,sell));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int idx = n - 1; idx >= 0; --idx) {
            for (int bought = 0; bought <= 1; ++bought) {
                int buy = 0, sell = 0;
                int notBuy = dp[idx + 1][bought];
                if (bought == 0) {
                    buy = -prices[idx] + dp[idx + 1][1];
                } else {
                    sell = prices[idx] - fee + dp[idx + 1][0];
                }
                dp[idx][bought] = max({buy, sell, notBuy});
            }
        }

        return dp[0][0];
    }
};