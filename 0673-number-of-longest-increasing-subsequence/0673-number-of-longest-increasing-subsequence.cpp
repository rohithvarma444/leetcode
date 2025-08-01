class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1);
        vector<int> cnt(n,1);


        for(int i = 1; i < n; i++){
            for(int prev  = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(1+dp[prev] == dp[i]){
                    cnt[i] = cnt[i] + cnt[prev];
                }
            }
        }

        int maxLen = 0;
        for(int i = 0; i < n; i++){
            maxLen = max(dp[i],maxLen);
        }

        int totalCnt = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxLen){
                totalCnt += cnt[i];
            }
        }

        return totalCnt;
    }
};