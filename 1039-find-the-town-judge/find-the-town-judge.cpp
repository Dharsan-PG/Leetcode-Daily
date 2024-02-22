class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> n(N+1, 0);

        for (int i = 0 ; i< trust.size(); i++) {
            n[trust[i][1]] += 1;
             n[trust[i][0]] -= 1;
        }

        for(int i =1 ; i< n.size(); i++) {
            if(n[i] == N-1) return i;
        }
        return -1;
    }
};