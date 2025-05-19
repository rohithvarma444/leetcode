class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while(i < n){
            int correctPos = nums[i];

            if(nums[i] < n && i != correctPos){
                swap(nums[i],nums[correctPos]);
            }
            else i++;
        }

        for(int i = 0; i < n; i++){
            if(nums[i] != i) return i;
        }
        return n;
    }
};