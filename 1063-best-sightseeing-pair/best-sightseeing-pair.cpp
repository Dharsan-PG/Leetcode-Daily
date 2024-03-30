class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> dp(n+1, -1);
        dp[0] = values[0];
        int maxi = 0;
        // for(int i = 1; i < n; i++) {
        //     maxi = max(maxi, solve(values, dp, i));
        // }
        for(int i = 1; i < n; i++) {
            maxi = max(maxi , dp[i-1] + values[i] - i);
            cout<<maxi<<" ";
            dp[i] = max(dp[i-1], values[i]+i);
            cout<<dp[i]<<endl;
        }
        // for(auto i : dp) cout<<i<<" ";
        return maxi;
    }

    int solve(vector<int>& values, vector<int>& dp, int i) {
        if(dp[i] != -1) {
            return dp[i];
        }
        int temp = 0;
        for(int j = 0; j< i; j++) {
            temp = max(temp, values[j] + values[i] + j - i);
        }

        return dp[i] = temp;
    }
};