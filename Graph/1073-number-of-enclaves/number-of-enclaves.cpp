class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<int> dr = {0,-1,0,1};
        vector<int> dc = {-1,0,1,0};
        int res = 0;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> vis(r , vector(c, false));

        for(int i = 0; i<r; i++) {
            for(int j = 0; j<c; j++) {
                if(grid[i][j] == 0 || vis[i][j]) continue;
                int n = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                bool flag = true;
                vis[i][j] = true;
                while(!q.empty()) {
                    auto node = q.front();
                    q.pop();
                    n++;
                    for(int k = 0; k<4; k++) {
                        int di = node.first + dr[k];
                        int dj = node.second + dc[k];
                        if(di<0 || di>=r || dj<0 || dj>=c) {
                            flag = false;
                            continue;
                        }
                        if(grid[di][dj] == 0) continue;
                        if(vis[di][dj]) continue;
                        q.push({di,dj});
                        vis[di][dj] = true;
                    }
                }
                if(flag == true) {
                    res += n;
                }
            }
        }
        return res;
    }
};