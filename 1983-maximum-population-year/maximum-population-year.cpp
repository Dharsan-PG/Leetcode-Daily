class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int ans = 0;
        int pop = 0;
        for(int i = 1950; i<2050; i++) {
            int t = 0;
            for(auto j : logs) {
                if(j[0] <= i) t++;
                if(j[1] <= i) t--;
            }
            if(t>pop) {
                ans = i;
                pop = t;
            }
        }
        return ans;
    }
};