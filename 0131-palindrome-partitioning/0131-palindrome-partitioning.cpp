class Solution {
public:
    bool isPalindrome(int left,int right,string s){
        while(left <= right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void helper(string s,int idx,vector<string> &path,vector<vector<string>> &ans){
        if(idx == s.size()){
            ans.push_back(path);
            return;
        }

        for(int i = idx;i < s.size(); i++){
            if(isPalindrome(idx,i,s)){
                path.push_back(s.substr(idx, i-idx+1));
                helper(s,i+1,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> path;
        vector<vector<string>> ans;
        helper(s,0,path,ans);
        return ans;
    }
};