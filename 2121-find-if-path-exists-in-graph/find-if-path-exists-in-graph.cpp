class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<bool> vis(n, 0);
        vector<int> adj[n];
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        queue<int> q1;
        q1.push(source);
        vis[source] = 1;
        while (!q1.empty()) {
            auto node = q1.front();
            q1.pop();
            if (node == destination)
                return true;

            for (auto i : adj[node]) {
                if (vis[i])
                    continue;
                vis[i] = 1;
                q1.push(i);
            }
        }
        return false;
    }
};

