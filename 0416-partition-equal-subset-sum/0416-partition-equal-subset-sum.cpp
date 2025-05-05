class Solution {
public:
    bool helper(vector<int> &nums,int n,vector<vector<int>> &dp,int idx,int target){
        if(target == 0) return true;
        if(idx == n) return false;

        if(dp[idx][target] != -1) return dp[idx][target];

        bool take = false;
        if(nums[idx] <= target){
            take = helper(nums,n,dp,idx+1,target-nums[idx]);
        }

       bool notTake = helper(nums,n,dp,idx+1,target);

        return dp[idx][target] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(auto it: nums){
            totalSum += it;
        }

        if(totalSum % 2 != 0) return false;
        vector<vector<int>> dp(n, vector<int>((totalSum/2)+1,-1));
        return helper(nums,n,dp,0,totalSum/2);
    }
};