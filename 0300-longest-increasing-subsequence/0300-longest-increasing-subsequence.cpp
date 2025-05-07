class Solution {
public:
    int helper(vector<int> &nums, vector<vector<int>> &dp, int idx, int prev, int n) {
        if (idx == n) return 0;

        if (dp[idx][prev + 1] != -1) return dp[idx][prev + 1];

        int take = 0;
        if (prev == -1 || nums[prev] < nums[idx]) {
            take = 1 + helper(nums, dp, idx + 1, idx, n);
        }

        int notTake = helper(nums, dp, idx + 1, prev, n);

        return dp[idx][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); 

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int take = 0;
                if (prev == -1 || nums[prev] < nums[i]) {
                    take = 1 + dp[i + 1][i + 1];  
                }
                int notTake = dp[i + 1][prev + 1];  

                dp[i][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0]; 
    }
};