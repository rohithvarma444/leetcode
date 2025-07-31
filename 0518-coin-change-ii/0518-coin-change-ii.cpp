class Solution {
public:
    int helper(vector<int> &coins,int index,int target,vector<vector<int>> &dp){
        if(index == 0){
            if(target % coins[0] ==0) return 1;
            return 0;
        }

        if(dp[index][target] != -1) return dp[index][target];

        int notTake = helper(coins,index-1,target,dp);
        int take = 0;
        if(coins[index] <= target) take = helper(coins,index,target - coins[index],dp);

        return dp[index][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        return helper(coins,coins.size()-1,amount,dp);
    }
};