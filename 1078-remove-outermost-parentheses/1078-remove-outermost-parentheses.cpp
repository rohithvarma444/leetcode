class Solution {
public:
    string removeOuterParentheses(string s) {
        int currOpen = 0;
        int currClose = 0;
        int left = 0;
        int right = 0;
        string ans = "";
        int n = s.size();
        
        while(right < n){
            if(s[right] == '(') currOpen++;
            else currClose++;

            if(currOpen == currClose){
                ans += s.substr(left+1, right-left-1);
                left = right+1;
            }
            right++;
        }


        return ans;

    }
};