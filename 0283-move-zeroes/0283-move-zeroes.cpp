class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int currIdx = 0;
        for(auto it: nums){
            if(it != 0) nums[currIdx++] = it;
        }

        for(int i = currIdx; i < n; i++){
            nums[i] = 0;
        }

        return;
    }
};