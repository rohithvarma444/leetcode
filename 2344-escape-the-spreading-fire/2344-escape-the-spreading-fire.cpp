class Solution {
public:
    int m, n;
    vector<vector<int>> fireTime;
    vector<vector<int>> dirs = {{-1,0}, {0,-1}, {1,0}, {0,1}};

    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    void computeFireTime(vector<vector<int>>& grid) {
        fireTime.assign(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    fireTime[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (isValid(nx, ny) && grid[nx][ny] != 2 && fireTime[nx][ny] == INT_MAX) {
                    fireTime[nx][ny] = fireTime[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    bool canReach(vector<vector<int>>& grid, int waitTime) {
        vector<vector<int>> vis(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = waitTime;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            int currTime = vis[x][y];

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (!isValid(nx, ny) || grid[nx][ny] == 2) continue;

                int nextTime = currTime + 1;

                if (nextTime >= fireTime[nx][ny]) {
                    if (nx == m - 1 && ny == n - 1 && nextTime <= fireTime[nx][ny]) {
                        return true;
                    }
                    continue;
                }

                if (vis[nx][ny] != -1) continue;

                vis[nx][ny] = nextTime;
                if (nx == m - 1 && ny == n - 1) return true;
                q.push({nx, ny});
            }
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        computeFireTime(grid);

        int low = 0, high = 1e9;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canReach(grid, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans >= int(1e9) ? int(1e9) : ans;
    }
};