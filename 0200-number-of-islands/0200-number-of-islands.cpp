class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;

        int cnt = 0;
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,-1,0,1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    vis[i][j] = 1;
                    cnt++;
                    q.push({i,j});
                }

                while(!q.empty()){
                    int currX = q.front().first;
                    int currY = q.front().second;
                    q.pop();

                    for(int i = 0; i < 4; i++){
                        int nx = currX + dr[i];
                        int ny = currY + dc[i];

                        if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1' && vis[nx][ny] == 0){
                            vis[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }

        return cnt;

    }
};