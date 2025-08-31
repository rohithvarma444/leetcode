class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            xorSum ^= nums[i];
        }
        return xorSum;
    }
};