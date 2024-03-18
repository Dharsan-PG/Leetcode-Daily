class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        priority_queue<pair<int,pair<int,int>>> q;
        q.push({mat[0][0], {0,0}});
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while(!q.empty()) {
            auto node = q.top();
            q.pop();
            int m = node.second.first, n = node.second.second;
            bool flag = true;            
            for(int i = 0; i<4; i++) {
                int x = m + dx[i];
                int y = n + dy[i];
                if(x>=0 && y>=0 && x<mat.size() && y<mat[0].size() && mat[x][y]>= mat[m][n]) {
                    q.push({mat[x][y], {x,y}});
                    flag = false;
                }
            }
            if(flag) return vector<int>{m,n};
        }
        return {};
    }
};