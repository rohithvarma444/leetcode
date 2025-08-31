class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> ans;
        queue<int> q;

        vector<vector<int>> adj(numCourses);

        for(auto it: pre){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> inOrder(numCourses,0);
        for(auto it: adj){
            for(auto at: it){
                inOrder[at]++;
            }
        }

        for(int i = 0; i < numCourses; i++){
            if(inOrder[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){

            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for(auto it: adj[curr]){
                inOrder[it]--;
                if(inOrder[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans.size() == numCourses? ans: vector<int> ();
    }
};