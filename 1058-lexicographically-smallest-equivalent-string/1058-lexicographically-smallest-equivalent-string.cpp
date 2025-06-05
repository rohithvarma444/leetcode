class DSU{

    public: 
    
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int u){
        if(parent[u] == u) return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unionByRank(char u, char v){
        int uPar = findUPar(u-'a');
        int vPar = findUPar(v-'a');

        if(uPar == vPar) return;

        if(uPar < vPar){
            parent[vPar] = uPar;
        }
        else{
            parent[uPar] = vPar; 
        }
    }

};




class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        if(n == 0) return baseStr;
        DSU ds(26);

        for(int i = 0; i < n; i++){
            ds.unionByRank(s1[i],s2[i]);
        }

        string res = "";
        for(auto it: baseStr){
            res += (ds.findUPar(it-'a')) + 'a';
        }

        return res;
    }
};