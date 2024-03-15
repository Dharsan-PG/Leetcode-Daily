class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& vis, int dr[], int dc[], int n, int m) {

        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                board[nr][nc] == 'O' && !vis[nr][nc]) {

                dfs(nr, nc, board, vis, dr, dc, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                dfs(0, j, board, vis, dr, dc, n, m);
            }
            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {
                dfs(n - 1, j, board, vis, dr, dc, n, m);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, board, vis, dr, dc, n, m);
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(i, m - 1, board, vis, dr, dc, n, m);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};