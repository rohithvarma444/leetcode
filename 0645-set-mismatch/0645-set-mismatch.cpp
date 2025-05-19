class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            int correctPos = nums[i]-1;

            if( i != correctPos && nums[correctPos] != correctPos + 1) swap(nums[i],nums[correctPos]);
            else i++;
        }

        for(auto it: nums){
            cout << it << " ";
        }

        

        for(int i = 0; i < n; i++){
            if(nums[i] != i+1) return {nums[i],i+1};
        }

        return {};
    }
};