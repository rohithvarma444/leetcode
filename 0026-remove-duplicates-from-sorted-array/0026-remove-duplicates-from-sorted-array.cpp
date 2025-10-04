class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int currIdx = 0;

        for(int i = 1; i < n; i++){
            if(nums[currIdx] != nums[i]){
                nums[++currIdx] = nums[i];
            }
        }

        return currIdx+1;
    }
};