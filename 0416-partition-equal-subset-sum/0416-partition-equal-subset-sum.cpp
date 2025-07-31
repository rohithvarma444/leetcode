class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        if(n==2) return nums[0] == nums[1];

        int totalSum = 0;
        for(auto it: nums){
            totalSum += it;
        }

        if(totalSum%2 != 0) return false;

        vector<vector<bool>> dp(n, vector<bool>((totalSum / 2) + 1, false));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        } 

        if (nums[0] <= totalSum / 2){
            dp[0][nums[0]] = true;
        }

        for(int i =1; i < n; i++){
            for(int target = 0; target <= (totalSum/2); target++){
                bool take = false;
                if(nums[i] <= target) take = dp[i-1][target-nums[i]];
                bool notTake = dp[i-1][target];


                dp[i][target] = take || notTake;
            }
        }

        return dp[n-1][totalSum/2];
    }
};