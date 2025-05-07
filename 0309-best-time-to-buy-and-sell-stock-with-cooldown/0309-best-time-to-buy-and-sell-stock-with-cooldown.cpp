class Solution {
public:
    int helper(vector<int> prices,vector<vector<int>> &dp,int n,int idx,int bought){
        if(idx >= n) return 0;

        if(dp[idx][bought] != -1) return dp[idx][bought];

        int buy = 0;
        int sell = 0;
        int notBuy = helper(prices,dp,n,idx+1,bought);

        if(bought == 0) buy = -prices[idx] + helper(prices,dp,n,idx+1,1);
        if(bought == 1) sell = prices[idx] + helper(prices,dp,n,idx+2,0);

        return dp[idx][bought] = max(buy, max(sell,notBuy));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));

        return helper(prices,dp,n,0,0);

    }
};