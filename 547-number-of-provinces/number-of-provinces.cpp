class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size() , vector<int>());
        for(int i = 0; i< isConnected.size(); i++) {
            for(int j = 0; j< isConnected[i].size(); j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int res = 0;
        vector<int> vis(isConnected.size(), 0);
        for(int i = 0; i< vis.size(); i++) {
            if(vis[i] == 0) {
                res++;
                dfs(i , adj, vis);
            }
        }

        return res;
    }

    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis) {
        vis[i] = 1;
        for(auto& j : adj[i]) {
            if(vis[j] == 0) {
                dfs(j , adj, vis);
            }
        }
    }
};