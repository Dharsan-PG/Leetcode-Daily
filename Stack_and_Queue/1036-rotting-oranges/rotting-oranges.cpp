class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int cnt = -1, f = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1)
                    f++;
            }
        }

        if (f == 0)
            return 0;
        if (q.empty())
            return -1;
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x + 1 < m && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    q.push({x + 1, y});
                    f--;
                }
                if (y + 1 < n && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    q.push({x, y + 1});
                    f--;
                }
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    q.push({x - 1, y});
                    f--;
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    q.push({x, y - 1});
                    f--;
                }
            }
            cnt++;
        }

        if (f == 0)
            return cnt;
        return -1;
    }
};