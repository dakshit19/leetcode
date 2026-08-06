class Solution {
public:
    vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n= mat.size();
        int m= mat[0].size();
        queue<pair<pair<int, int>, int>> q; // row, col, dist
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> grid(n, vector<int>(m, 0));
        //filling vis 
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mat[i][j]==0) {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                } 
            }
        }
        
        vector<int> dr= {-1,1,0,0};
        vector<int> dc= {0,0,-1,1};
        while (!q.empty()) {
            int cr= q.front().first.first;
            int cc= q.front().first.second;
            int dist= q.front().second;
            q.pop();
            grid[cr][cc]= dist;

            for (int k=0; k<4; k++) {
                int nr= cr+ dr[k];
                int nc= cc+ dc[k];
                if (nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0) {
                    vis[nr][nc]= 1;
                    q.push({{nr, nc}, dist+1});
                }
            }
        }

        return grid;
    }
};