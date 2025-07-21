class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &vis, int src) {
        vis[src] = 1;
        for (auto it : adj[src]) {
            if (!vis[it])
                dfs(adj, vis, it);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j)
                    adj[i].push_back(j);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(adj, vis, i);
            }
        }

        return cnt;
    }
};
