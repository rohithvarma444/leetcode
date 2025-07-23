class Disjoint {
public:
    vector<int> parent, size, rank;
    
    Disjoint(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unionBySize(int u, int v) {
        int upU = findUPar(u);
        int upV = findUPar(v);
        if (upU == upV) return;
        if (size[upU] < size[upV]) {
            parent[upU] = upV;
            size[upV] += size[upU];
        } else {
            parent[upV] = upU;
            size[upU] += size[upV];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint ds(n * n);

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                for(int k = 0; k < 4; k++) {
                    int newR = i + dr[k];
                    int newC = j + dc[k];
                    if(newR >= 0 && newR < n && newC >= 0 && newC < n && grid[newR][newC] == 1) {
                        int rowNo = i * n + j;
                        int newRNo = newR * n + newC;
                        ds.unionBySize(rowNo, newRNo);
                    }
                }
            }
        }

        int mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) continue;
                unordered_set<int> components;
                int totalSize = 1;
                for(int k = 0; k < 4; k++) {
                    int newR = i + dr[k];
                    int newC = j + dc[k];
                    if(newR >= 0 && newR < n && newC >= 0 && newC < n && grid[newR][newC] == 1) {
                        int root = ds.findUPar(newR * n + newC);
                        if(components.find(root) == components.end()) {
                            components.insert(root);
                            totalSize += ds.size[root];
                        }
                    }
                }
                mx = max(mx, totalSize);
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            if(ds.findUPar(cellNo) == cellNo) {
                mx = max(mx, ds.size[cellNo]);
            }
        }

        return mx;
    }
};