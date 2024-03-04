class Solution {
public:
    int dp[1001][1001];
    int solve(int l, int r, int p, vector<int>& tokens) {
        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;
        if (tokens[l] <= p)
            ans = 1 + solve(l + 1, r, p - tokens[l], tokens);
        if (l > tokens.size() - 1 - r)
            ans = max(ans, -1 + solve(l, r - 1, p + tokens[r], tokens));

        return dp[l][r] = ans;
    }

    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        memset(dp, -1, sizeof(dp));
        return solve(0, tokens.size() - 1, power, tokens);
    }
};