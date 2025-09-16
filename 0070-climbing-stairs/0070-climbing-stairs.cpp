class Solution {
public:
    int helper(int idx, vector<int> &dp){
        if(idx == 0) return 1;
        if(idx < 0) return 0;

        if(dp[idx] != -1 ) return dp[idx];

        int oneStep = helper(idx-1,dp);
        int twoStep = helper(idx-2,dp);

        return dp[idx] = oneStep + twoStep;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n,dp);
    }
};