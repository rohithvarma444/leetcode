class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int i = 0; i <= n; i++){
            totalSum += i;
        }

        int actualSum = 0;
        for(int i = 0; i < n; i++){
            actualSum += nums[i];
        }

        return totalSum - actualSum;
    }
};