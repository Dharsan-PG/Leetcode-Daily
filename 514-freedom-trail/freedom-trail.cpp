class Solution {
public:
    int dp[101][101];
    unordered_map<int, vector<int>> mp;
    int solve(string& r, string& k, int i, int prev, int n, int m) {
        if (i >= m) {
            return 0;
        }
        if (dp[i][prev] != -1) {
            return dp[i][prev];
        }
        int ans = 1e9;
        for (auto it : mp[k[i]]) {
            ans = min({ans, abs(it - prev) + 1 + solve(r, k, i + 1, it, n, m),
                       n - abs(it - prev) + 1 + solve(r, k, i + 1, it, n, m)});
        }
        return dp[i][prev] = ans;
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) {
            mp[ring[i]].push_back(i);
        }
        int y = solve(ring, key, 0, 0, n, m);
        return y;
    }
};