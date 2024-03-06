class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(0, 3, n, nums, dp, mod);
    }

    int solve(int i, int prev, int n, vector<int>& nums,
              vector<vector<int>>& dp, int& mod) {
        if (i == n)
            return prev == 2;

        if (dp[i][prev] != -1)
            return dp[i][prev];

        if (check(prev, nums[i])) {
            int pick = solve(i + 1, nums[i], n, nums, dp, mod);
            int notpick = solve(i + 1, prev, n, nums, dp, mod);
            return dp[i][prev] = (pick + notpick) % mod;
        }

        return dp[i][prev] = solve(i + 1, prev, n, nums, dp, mod);
    }

    int check(int prev, int i) {
        if (i == 0)
            return prev == 3 || prev == 0;
        else if (i == 1)
            return prev == 0 || prev == 1;
        return prev == 1 || prev == 2;
    }
};