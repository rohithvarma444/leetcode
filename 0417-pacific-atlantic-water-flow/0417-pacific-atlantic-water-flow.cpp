class Solution {
public:

    void dfs(int r,int c,vector<vector<int>>& visited,vector<vector<int>> &heights,int m,int n){
        visited[r][c] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0&&nc>=0&&nr<m&&nc<n&&visited[nr][nc]==0){
                if(heights[nr][nc]>=heights[r][c]){
                    dfs(nr,nc,visited,heights,m,n);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n= heights[0].size();

        vector<vector<int>> ans;
        vector<vector<int>> atlantic(m,vector<int>(n,0));
        vector<vector<int>> pacific(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0) dfs(i,j,pacific,heights,m,n);
                if(i==m-1||j==n-1) dfs(i,j,atlantic,heights,m,n);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlantic[i][j] == 1 && pacific[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};