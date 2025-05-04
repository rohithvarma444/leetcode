class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,-1));

        for(int i =0; i < n; i++){
            dp[m-1][i] = matrix[m-1][i];
        }

        for(int i = m-2; i >= 0; i--){
            for(int j = 0; j < n; j++){

                int below = dp[i+1][j] + matrix[i][j];
                int diagL = INT_MAX;
                if(j > 0){
                    diagL = dp[i+1][j-1] + matrix[i][j];
                }
                int diagR = INT_MAX;
                if( j!= n-1){
                    diagR = dp[i+1][j+1] + matrix[i][j];
                }


                dp[i][j] = min(diagL,min(diagR,below));
            }
        }


        int ans = dp[0][0];
        for(int i =0; i < n; i++){
            ans = min(ans,dp[0][i]);
        }

        return ans;
    }
};