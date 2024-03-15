class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // if(image[sr][sc] != (color-1)) return image;
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<bool>> vis(image.size(),vector<bool>(image[0].size(), false));
       
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            for(auto i : dir) {
                int dr = r - i.first;
                int dc = c - i.second;
                if((dr>=0 && dr<image.size() && dc>=0 && dc<image[0].size()) && !vis[dr][dc]){
                    if(image[dr][dc] == image[r][c]) {q.push({dr, dc}); vis[dr][dc] = true;} 
                }
                
            }
            image[r][c] = color;
        }
        return image;
    }
};