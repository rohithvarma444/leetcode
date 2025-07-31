class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,1e5));
        
        for(int i = 0; i < n; i++) dp[i][0] = 0;
        
        for(int i = 0; i <= amount; i++){
            if( i % coins[0] == 0) dp[0][i] = i/coins[0];
        }

        for(int i = 1; i < n; i++){
            for(int target = 1; target <= amount; target++){
                int take = 1e5;
                if(coins[i] <= target) take = 1 + dp[i][target - coins[i]];
                int notTake = dp[i-1][target];

                dp[i][target] = min(take,notTake);
            }
        }

        return (dp[n-1][amount] >= 1e5)? -1: dp[n-1][amount];
    }
};