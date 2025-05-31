class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(auto it: rooms[i]){
                adj[i].push_back(it);
            }
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto it: adj[curr]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        for(auto it: vis){
            if(it == 0) return false;
        }

        return true;
    }
};