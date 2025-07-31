class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(3,0)));   

        for(int i = n-1; i>=0; i--){
            for(int canBuy = 0; canBuy < 2; canBuy++){
                for(int k = 1; k < 3; k++){
                    if(canBuy == 1){
                        dp[i][canBuy][k] = max(dp[i+1][1][k], -prices[i] + dp[i+1][0][k]);
                    }

                    else dp[i][canBuy][k] = max(dp[i+1][0][k], prices[i] + dp[i+1][1][k-1]);
                }
            }
        }

        return dp[0][1][2];

    }
};