class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        while(!pq.empty()){
            int currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto it: adj[currNode]){
                int adjNode = it.first;
                int weight = it.second;

                if(dist[adjNode] > currDist + weight){
                    dist[adjNode] = currDist + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }


        int maxi = 0;
        for(int i = 1; i <=n ; i++){
            if(dist[i] == 1e9) return -1;
            maxi = max(maxi,dist[i]);
        }
        return maxi;
    }
};