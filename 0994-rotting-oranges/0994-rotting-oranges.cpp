class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows= grid.size();
        int colms= grid[0].size();
        int arr[rows][colms];
        queue<pair<pair<int, int>, int>> q; // row, colm, time

        //initializing grid
        for (int i=0; i<rows; i++) {
            for (int j=0; j<colms; j++) {
                if (grid[i][j]==2) {
                    q.push({{i, j}, 0});
                    arr[i][j]=2;
                } else arr[i][j]= 0;
            }
        }

        int minutes=0;
        int dr[]= {0,0,+1,-1};
        int dc[]= {-1,+1,0, 0};
        while (!q.empty()) {
            auto curr= q.front();
            q.pop();
            int cr= curr.first.first;
            int cc= curr.first.second;
            int ct= curr.second;
            minutes= max(minutes, ct);
            //check all neighbours
            for (int i=0; i<4; i++) {
                int r= cr+ dr[i];
                int c= cc+ dc[i];
                if (r<rows && c<colms && r>=0 && c>=0 && grid[r][c]==1 && arr[r][c]!=2){
                    arr[r][c]=2;
                    q.push({{r, c}, ct+1});
                }
            }
        }

        //check for -1 condition
        for (int i=0; i<rows; i++) {
            for (int j=0; j<colms; j++) {
                if (arr[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }

        return minutes;
    }
};