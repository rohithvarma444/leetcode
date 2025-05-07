class Solution {
public:
    int helper(vector<int> &prices, vector<vector<vector<int>>> &dp, int n, int idx, int bought, int k){
    if(idx == n || k == 0) return 0;
    if(dp[idx][bought][k] != -1) return dp[idx][bought][k]; // memoization check

    int buy = 0;
    int sell = 0;
    int notBuy = helper(prices,dp,n,idx+1,bought,k);
    if(k > 0 && bought == 0){
        buy = -prices[idx] + helper(prices,dp,n,idx+1,1,k);
    }
    if(bought == 1 && k > 0){
        sell = prices[idx] + helper(prices,dp,n,idx+1,0,k-1);
    }

    return dp[idx][bought][k] = max(buy, max(notBuy,sell));
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return helper(prices,dp,n,0,0,2);
    }
};