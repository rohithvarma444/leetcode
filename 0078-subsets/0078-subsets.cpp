class Solution {
public:
    void helper(int idx,vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        helper(idx+1,nums,ans,temp);
        temp.pop_back();
        helper(idx+1,nums,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,nums,ans,temp);
        return ans;
    }
};