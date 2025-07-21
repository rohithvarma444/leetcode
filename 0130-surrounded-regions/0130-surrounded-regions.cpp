class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,-1,0,1};

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if( i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while(!q.empty()){
            int currX = q.front().first;
            int currY = q.front().second;

            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = currX + dr[i];
                int nc = currY + dc[i];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == 'O'){
                    if(!vis[nr][nc]){
                        q.push({nr,nc});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

        
    }
};