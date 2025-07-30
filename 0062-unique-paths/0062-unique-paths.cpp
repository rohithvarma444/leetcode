class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = 1;
        
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(x == 0 && y == 0) continue; 
                
                int up = 0, left = 0;
                
                if(x-1 >= 0) up = dp[x-1][y];
                
                if(y-1 >= 0) left = dp[x][y-1];
                
                dp[x][y] = up + left;
            }
        }
        
        return dp[m-1][n-1];
    }
};
