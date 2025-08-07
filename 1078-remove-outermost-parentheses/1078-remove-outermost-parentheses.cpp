class Solution {
public:
    string removeOuterParentheses(string s) {
        int currOpen = 0;
        int currClose = 0;
        int left = 0;
        int right = 0;
        int n = s.size();
        string ans = "";

        while(right < n){
            if(s[right] == '(') currOpen++;
            else if(s[right] == ')') currOpen--;

            if(currOpen == 0) {
                ans += s.substr(left+1, right - left - 1);
                left = right + 1;
            }
            right++;
        }

        return ans;
    }
};