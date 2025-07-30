class Solution {
public:
    int helper(int idx,int n,vector<int> &dp,vector<int> &nums){
        if(idx >= n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int rob = nums[idx] + helper(idx+2,n,dp,nums);
        int notRob = helper(idx+1,n,dp,nums);

        return dp[idx] = max(rob,notRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return helper(0,n,dp,nums);
    }
};