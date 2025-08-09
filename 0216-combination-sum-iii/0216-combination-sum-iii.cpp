class Solution {
public:
    void helper(int idx,vector<int> temp,vector<vector<int>> &ans,int k,int n){
        if( k == 0 && n == 0){
            ans.push_back(temp);
            return;
        }

        if(k==0 && n!=0 || k!=0 && n == 0) return;
        if(n<0) return;

        for(int i = idx + 1; i <= 9; i++){
            temp.push_back(i);
            helper(i,temp,ans,k-1,n-i);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i = 1; i <= 9; i++) nums.push_back(i);

        vector<vector<int>> ans;
        helper(0,{},ans,k,n);

        return ans;
    }
};