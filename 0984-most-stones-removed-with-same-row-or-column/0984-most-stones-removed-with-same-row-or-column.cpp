class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int n) {
        if (parent[n] == n) return n;
        return parent[n] = findUPar(parent[n]); 
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++; 
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto& it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2); 
        unordered_set<int> nodes; 

        for (auto& it : stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1; 
            ds.unionByRank(row, col);

            nodes.insert(row);
            nodes.insert(col);
        }

        int components = 0;
        for (auto node : nodes) {
            if (ds.findUPar(node) == node) components++;
        }

        return stones.size() - components;
    }
};