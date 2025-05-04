class Solution {
public:
    int helper(int m,int n,vector<vector<int>> &dp,vector<vector<int>> &grid,int x, int y){
        if(x >= m || y >= n || x <0 || y < 0) return 1e9;
        if(dp[x][y] != -1) return dp[x][y];

        if (x == m - 1 && y == n - 1) return grid[x][y];

        int down =  helper(m,n,dp,grid,x+1,y);
        int right = helper(m,n,dp,grid,x,y+1);

        return dp[x][y] = grid[x][y] + min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return helper(m,n,dp,grid,0,0);
    }
};