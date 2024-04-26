class Solution {
public:
    int path(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (j < 0 || j >= grid.size())
            return 1e8;
        if (i == 0)
            return grid[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for (int k = 0; k < grid.size(); k++) {
            if (k == j)
                continue;
            ans = min(ans, grid[i][j] + path(i - 1, k, grid, dp));
        }
        return dp[i][j] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int mini = INT_MAX;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); i++) {
            mini = min(mini, path(grid.size() - 1, i, grid, dp));
        }
        return mini;
    }
};