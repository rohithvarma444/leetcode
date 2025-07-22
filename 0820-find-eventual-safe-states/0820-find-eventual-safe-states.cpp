class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> revAdj(n);
        vector<int> inDegree(n, 0);
        
        for(int u = 0; u < n; ++u) {
            for(auto v : graph[u]) {
                revAdj[v].push_back(u);
                inDegree[u]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;

        while(!q.empty()) {
            int node = q.front(); q.pop();
            safe.push_back(node);

            for(auto neighbor : revAdj[node]) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};