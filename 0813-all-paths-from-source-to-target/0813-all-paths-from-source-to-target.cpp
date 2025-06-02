class Solution {
public:
    void helper(vector<vector<int>>& graph, vector<vector<int>>& ans,int src,int n,vector<int> &temp){
        temp.push_back(src);

        if(src == n){
            ans.push_back(temp);
            return;
        }

        for(auto it: graph[src]){
            helper(graph,ans,it,n,temp);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        vector<int> temp;
        helper(graph,ans,0,n-1,temp);
        return ans;
    }
};