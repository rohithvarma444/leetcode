class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e5;
        int n = coins.size();
        vector<int> prev(amount+1, INF), curr(amount+1, INF);
        prev[0] = 0;
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) prev[t] = t / coins[0];
        }
        for (int i = 1; i < n; i++) {
            curr[0] = 0;
            for (int t = 1; t <= amount; t++) {
                int take = INF;
                if(coins[i] <= t) take = 1 + curr[t - coins[i]];
                int notTake = prev[t];
                curr[t] = min(take, notTake);
            }
            prev = curr;
        }
        return (prev[amount] >= INF) ? -1 : prev[amount];
    }
};
