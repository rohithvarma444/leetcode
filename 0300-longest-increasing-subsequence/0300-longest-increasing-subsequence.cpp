class Solution {
public:
    int helper(vector<int> &nums,int idx,int n,vector<vector<int>> &dp,int prev){
        if( idx == n){
            return 0;
        }

        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev]){
            take = 1 + helper(nums,idx+1,n,dp,idx);
        }
        int notTake = helper(nums,idx+1,n,dp,prev);

        return dp[idx][prev+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return helper(nums,0,n,dp,-1);
    }
};