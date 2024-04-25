class Solution {
public:
int solve(int i, int prev, string& s, int k, vector<vector<int>>& dp){
        if(i >= s.length()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        int take = 0;
        int ch = s[i]-'a'+1;
        if(prev == 0 || abs(ch-prev) <= k) take = 1 + solve(i+1, ch, s, k, dp);
        int nottake = solve(i+1, prev, s, k, dp);
        return dp[i][prev] = max(take, nottake);
    }
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(27, -1));
        return solve(0, 0, s, k, dp);
    }
};