class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int isRotated = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i+1)%n]){
                isRotated++;
            }
        }
        return isRotated <= 1;
    }
};