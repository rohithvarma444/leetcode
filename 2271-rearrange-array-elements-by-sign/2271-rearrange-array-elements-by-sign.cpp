class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ans(n);

        int posIndex = 0;
        int negIndex = 1;

        int currIdx = 0;

        while(currIdx < n){
            if(nums[currIdx] >= 0){
                ans[posIndex] = nums[currIdx]; 
                posIndex += 2;
            }
            else {
                ans[negIndex] = nums[currIdx]; 
                negIndex += 2; 
            }
            currIdx++;
        }

        return ans;
    }
};