class Solution {
public:
    int helper(int idx, vector<int> &coins,vector<vector<int>> &dp,int amount){
        if(amount == 0) return 0;
        if(idx == 0 && amount%coins[idx] == 0){
            return amount/coins[idx];
        }
        if(idx == 0) return 1e5;
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int take = 1e5;
        if(coins[idx] <= amount) take = 1 + helper(idx,coins,dp,amount-coins[idx]);
        int notTake = helper(idx-1,coins,dp,amount);

        return dp[idx][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = helper(n-1,coins,dp,amount);

        if(ans >= 1e5) return -1;
        return ans;

        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }

        if(coins[0] <= amount){

        }
    }
};