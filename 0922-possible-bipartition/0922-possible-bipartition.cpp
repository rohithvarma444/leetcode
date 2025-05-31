class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        vector<int> color(n + 1, -1); 

        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int curr = q.front(); q.pop();

                    for (int neighbor : adj[curr]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[curr];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[curr]) {
                            return false; 
                        }
                    }
                }
            }
        }

        return true;
    }
};