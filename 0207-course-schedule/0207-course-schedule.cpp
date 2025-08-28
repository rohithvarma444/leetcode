class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {

        vector<vector<int>> adj(numCourses);
        vector<int> inOrder(numCourses,0);

        for(auto it: pre){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            inOrder[u]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(inOrder[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto it: adj[curr]){
                inOrder[it]--;
                if(inOrder[it] == 0){
                    q.push(it);
                }
            }            
        }

        for(auto it: inOrder){
            if(it != 0) return false;
        }
        return true;
        
    }
};