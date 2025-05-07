class Solution {
public:
    int helper(int i, int j, string &text1, string &text2, vector<vector<int>> &dp){
        if(i == text1.size() || j == text2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + helper(i+1, j+1, text1, text2, dp);
        }

        return dp[i][j] = max(helper(i+1, j, text1, text2, dp),
                              helper(i, j+1, text1, text2, dp));
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return helper(0,0,s2,s,dp);
    }
};