class Solution {
public:
    int helper(int n, vector<int> &dp,int idx){
        if(idx == n) return 1;

        if(dp[idx] != -1) return dp[idx];

        int oneStep = helper(n,dp,idx+1);
        int twoStep = 0;
        if(idx < n-1){
            twoStep = helper(n,dp,idx+2);
        }
        return dp[idx] = oneStep + twoStep; 
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n,dp,0);
    }
};