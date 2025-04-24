class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int n) {
        if(parent[n] == n) return n;
        return parent[n] = findUPar(parent[n]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv) return;

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if(rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailToAcc;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if(emailToAcc.find(email) == emailToAcc.end()) {
                    emailToAcc[email] = i;
                } else {
                    ds.unionByRank(i, emailToAcc[email]);
                }
            }
        }

        unordered_map<int, vector<string>> mergedEmails;
        for(auto& [email, idx] : emailToAcc) {
            int parent = ds.findUPar(idx);
            mergedEmails[parent].push_back(email);
        }

        vector<vector<string>> ans;
        for(auto& [idx, emails] : mergedEmails) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[idx][0]); 
            ans.push_back(emails);
        }

        return ans;
    }
};