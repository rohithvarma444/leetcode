class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
        for(int i = 0; i <= n1; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i <= n2; i++){
            dp[0][i] = 0;
        }

        for(int s1 = 1; s1 <= n1; s1++){
            for(int s2=1; s2 <= n2; s2++){
                if(word1[s1-1] == word2[s2-1]){
                    dp[s1][s2] = dp[s1-1][s2-1]+1;
                }
                else dp[s1][s2] = max(dp[s1-1][s2],dp[s1][s2-1]);
            }
        }
        return n1+n2-(2*dp[n1][n2]);
    }
};