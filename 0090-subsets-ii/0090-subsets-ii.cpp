class Solution {
public:
    void helper(vector<int> &nums,vector<vector<int>> &ans,vector<int> temp,int idx){
        ans.push_back(temp);
        for(int i=idx; i < nums.size(); i++){
            if(i > idx && nums[i-1] == nums[i]) continue;
            temp.push_back(nums[i]);
            helper(nums,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums,ans,temp,0);
        return ans;
    }
};