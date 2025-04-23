#include <bits/stdc++.h>
using namespace std;

class Disjoint {
public:
    vector<int> parent, size, rank;
    
    Disjoint(int n) {
        parent.resize(n + 1);
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

    void unionByRank(int u, int v) {
        int upU = findUPar(u);
        int upV = findUPar(v);
        if (upU == upV) return;
        if (rank[upU] < rank[upV]) {
            parent[upU] = upV;
        } else if (rank[upV] < rank[upU]) {
            parent[upV] = upU;
        } else {
            parent[upV] = upU;
            rank[upU]++;
        }
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        map<string, int> mpp; 

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (mpp.find(email) == mpp.end()) {
                    mpp[email] = i;
                } else {
                    ds.unionByRank(i, mpp[email]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for (auto it : mpp) {
            string email = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(email);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());  
            vector<string> temp;
            temp.push_back(accounts[i][0]); 
            temp.insert(temp.end(), mergedMail[i].begin(), mergedMail[i].end());
            ans.push_back(temp);
        }

        return ans;
    }
};