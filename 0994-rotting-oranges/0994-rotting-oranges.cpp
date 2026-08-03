class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row= grid.size();
        int col= grid[0].size();
        int vis[row][col];
        queue<pair<pair<int, int>, int>> q; // row, col, time

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (grid[i][j]==2) {
                    vis[i][j]=2;
                    q.push({{i, j}, 0});
                } else vis[i][j]=0;
            }
        }

        int res=0;
        //neighbour grid element i,j
        int drow[]= {+1,-1,0,0};
        int dcol[]= {0, 0, -1, +1};
        while (!q.empty()) {
            auto curr= q.front();
            q.pop();
            int cr= curr.first.first;
            int cc= curr.first.second;
            int ct= curr.second;
            res= max(res, ct);

            for (int i=0; i<4; i++) {
                int nr= cr+ drow[i];
                int nc= cc+ dcol[i];
                if (nr>=0 && nc>=0 && nr<row && nc<col && grid[nr][nc]==1 && vis[nr][nc]==0) {
                    vis[nr][nc]= 2;
                    q.push({{nr, nc}, ct+1});
                } 
            }
        }

        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (grid[i][j]==1 && vis[i][j]==0) return -1;
            }
        }

        return res;
    }
};