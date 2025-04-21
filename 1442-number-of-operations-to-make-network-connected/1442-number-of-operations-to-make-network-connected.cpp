class DisjointSet {
public:
    vector<int> parent, rank, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        size.resize(n + 1, 1); 
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int n) {
        if (parent[n] == n) return n;
        return parent[n] = findUPar(parent[n]); 
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu]; 
        } else {
            parent[pv] = pu;
            size[pu] += size[pv]; 
        }
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int redundant = 0;
        int cnt = 0;

        for (auto it : connections) {
            if (ds.findUPar(it[0]) != ds.findUPar(it[1])) {
                ds.unionByRank(it[0], it[1]); 
            } else {
                redundant++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) cnt++;
        }

        return (redundant >= cnt - 1) ? cnt - 1 : -1;
    }
};