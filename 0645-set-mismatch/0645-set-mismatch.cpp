class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            int correctPos = nums[i]-1;

            if( i != correctPos && nums[i] != nums[correctPos]) swap(nums[i],nums[correctPos]);
            else i++;
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1) return {nums[i],i+1};
        }

        return {};
    }
};