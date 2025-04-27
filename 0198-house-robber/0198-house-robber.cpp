class Solution {
public:
    int helper(int n, vector<int> &dp,int idx,vector<int> &nums){
        if(idx >= n) return 0;

        if(dp[idx] != -1) return dp[idx];

        int rob = nums[idx] + helper(n,dp,idx+2,nums);
        int notRob = helper(n,dp,idx+1,nums);

        return dp[idx] = max(rob,notRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(n,dp,0,nums);
    }
};