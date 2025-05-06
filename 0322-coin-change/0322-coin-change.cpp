class Solution {
public:
    int helper(vector<int>& coins,vector<vector<int>> &dp,int n,int idx,int amount){
        if(amount == 0) return 0;
        if(idx == n) return 1e9;

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int take = 1e9;
        if(coins[idx] <= amount){
            take = 1 + helper(coins,dp,n,idx,amount-coins[idx]);
        }
        int notTake = helper(coins,dp,n,idx+1,amount);
        return dp[idx][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = helper(coins,dp,n,0,amount);
        return (ans == 1e9)? -1: ans;
    }
};