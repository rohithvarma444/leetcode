class Solution {
public:
    void helper(int n, string temp, vector<string> &ans,int totalOpen, int totalClose){
        if(totalOpen == n && totalClose == n){
            ans.push_back(temp);
            return;
        }

        if(totalOpen < n){
            helper(n,temp + "(",ans,totalOpen+1,totalClose);
        }
        if(totalClose < totalOpen){
            helper(n,temp + ")",ans,totalOpen,totalClose+1);
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        helper(n,temp,ans,0,0);
        return ans;
    }
};