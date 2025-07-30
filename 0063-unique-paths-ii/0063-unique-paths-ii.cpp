class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;  // ✅ Conditional initialization
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; 
                    continue;
                }
                
                if(i == 0 && j == 0) continue;  
                int bottom = 0, right = 0;
                
                if(i-1 >= 0){
                    bottom = dp[i-1][j];
                }
                
                if(j-1 >= 0){
                    right = dp[i][j-1];
                }

                dp[i][j] = bottom + right;
            }
        }

        return dp[m-1][n-1];
    }
};
