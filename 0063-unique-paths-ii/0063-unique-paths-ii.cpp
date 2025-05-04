class Solution {
public:
    int helper(int m, int n, vector<vector<int>> &dp,vector<vector<int>> &arr,int x,int y){
        if(x >= m || y >= n || x < 0 || y < 0) return 0;
        if(arr[x][y] == 1) return 0;
        if(x == m-1 && y == n-1) return 1;

        if(dp[x][y] != -1) return dp[x][y];

        int down = helper(m,n,dp,arr,x+1,y);
        int right= helper(m,n,dp,arr,x,y+1);

        return dp[x][y] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m,n,dp,obstacleGrid,0,0);
    }
};