class Solution {
public:
    int ans = 1;

    int dfs(int node, vector<vector<int>> &adj, string &s) {
        int max1 = 0, max2 = 0;

        for (int child : adj[node]) {
            int len = dfs(child, adj, s);
            if (s[child] != s[node]) {
                if (len > max1) {
                    max2 = max1;
                    max1 = len;
                } else if (len > max2) {
                    max2 = len;
                }
            }
        }

        ans = max(ans, max1 + max2 + 1);
        return max1 + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs(0, adj, s);
        return ans;
    }
};