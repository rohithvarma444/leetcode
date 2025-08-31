class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return; 
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));

        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(grid[i][j] == 'O' && !vis[i][j]){
                        q.push({i,j});
                        vis[i][j] = 1;
                    } 
                }
            }
        }

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,-1,0,1};

        while(!q.empty()){
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int newX = currX + dr[i];
                int newY = currY + dc[i];

                if(newX >= 0 && newY >= 0 && newX < m && newY < n 
                   && grid[newX][newY] == 'O' && !vis[newX][newY]){
                    vis[newX][newY] = 1;
                    q.push({newX,newY});
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'O' && !vis[i][j]){
                    grid[i][j] = 'X';
                }
            }
        }
    }
};