class Solution {
public:
    
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        return solve( 0, s, 0, t, dp);
    }

    int solve(int si, string s, int ti, string t, vector<vector<int>>& dp) {
        if(ti >= t.size()) return 1;
        if(si >= s.size()) return 0;
        if(dp[si][ti] != -1) return dp[si][ti];
        int pick = 0;
        int notpick = solve(si+1, s, ti, t, dp);
        if(s[si] == t[ti]) {
            pick = solve(si+1, s, ti+1, t, dp);
        }
        return dp[si][ti] = pick + notpick;
    }
};