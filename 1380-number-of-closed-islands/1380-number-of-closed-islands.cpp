class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        auto bfs = [&](int i, int j) {
            queue<pair<int,int>> q;
            q.push({i, j});
            vis[i][j] = 1;

            int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            while(!q.empty()){
                auto [x, y] = q.front(); q.pop();

                for(auto &d: dirs){
                    int nx = x + d[0], ny = y + d[1];
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n 
                       && grid[nx][ny] == 0 && !vis[nx][ny]){
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        };

        // 1️⃣ First pass: flood-fill all border 0’s
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) 
                   && grid[i][j] == 0 && !vis[i][j]){
                    bfs(i, j);
                }
            }
        }

        // 2️⃣ Second pass: count closed islands inside
        int cnt = 0;
        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};