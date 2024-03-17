class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> mp(n);
        vector<int> deg(n, 0);

        for(auto i : pre) {
            int from = i[0];
            int to = i[1];
            mp[from].push_back(to);
            deg[to]++;
        }

        queue<int> q;
        for(int i = 0; i<n; i++) {
            if(deg[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for(int i  : mp[node]) {
                if(--deg[i] == 0) q.push(i);
            }

        }


        return cnt == n;

    }
};