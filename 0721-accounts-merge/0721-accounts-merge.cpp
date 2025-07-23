class DisjointSet{
    public:
      vector<int> parent;
      vector<int> rank;
      vector<int> size;

      DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);
        size.resize(n,1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
      }

      int findUPar(int u){
        return (u == parent[u])? u: parent[u] = findUPar(parent[u]);
      }

      void unionByRank(int u,int v){
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) return;

        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
      }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int> mpp;
        DisjointSet ds(accounts.size());
        
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                
                if(mpp.find(accounts[i][j]) != mpp.end()){
                    if(ds.findUPar(mpp[accounts[i][j]]) != ds.findUPar(i)){
                        ds.unionByRank(mpp[accounts[i][j]], i);
                    }
                }
                else {
                    mpp[accounts[i][j]] = i;
                }
            }
        }

        map<int, vector<string>> mergedEmails;
        for(auto& it : mpp){
            string email = it.first;
            int node = it.second;
            int rootParent = ds.findUPar(node);
            mergedEmails[rootParent].push_back(email);
        }
        
        vector<vector<string>> ans;
        for(auto& it : mergedEmails){
            int rootNode = it.first;
            vector<string>& emails = it.second;
            
            sort(emails.begin(), emails.end());
            
            vector<string> temp;
            temp.push_back(accounts[rootNode][0]); 
            
            for(string& email : emails){
                temp.push_back(email);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};
