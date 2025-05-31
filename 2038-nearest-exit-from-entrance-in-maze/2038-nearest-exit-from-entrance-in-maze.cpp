class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};

        vector<vector<int>> vis(m, vector<int>(n, -1));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&
                    !(i == entrance[0] && j == entrance[1]) && maze[i][j] == '.') {
                    pq.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        while (!pq.empty()) {
            int steps = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == entrance[0] && y == entrance[1]) return steps;

            for (int i = 0; i < 4; i++) {
                int nr = x + dr[i];
                int nc = y + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == -1 && maze[nr][nc] == '.') {
                    vis[nr][nc] = 1;
                    pq.push({steps + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};