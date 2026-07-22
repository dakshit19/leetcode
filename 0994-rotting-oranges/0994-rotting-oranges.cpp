class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row= grid.size();
        int colm= grid[0].size();
        vector<vector<int>> arr(row, vector<int>(colm, 0)); // has rotten oranges 
        queue<pair<pair<int, int>, int>> q; // {row, colm}, time
        // mark intial rotten and put in queue to traverse neighbours
        for (int i=0; i<row; i++) { 
            for (int j=0; j<colm; j++) {
                if (grid[i][j]==2) {
                    q.push({{i, j}, 0});
                    arr[i][j]=2;
                }
            }
        }
        int mnts=0;
        while (!q.empty()) {
            auto curr= q.front();
            q.pop();
            int curr_row= curr.first.first;
            int curr_colm= curr.first.second;
            int curr_time= curr.second;
            mnts= max(mnts, curr_time);
            // row, col+1
            if (curr_row>=0 && curr_row<row && curr_colm>=0 && curr_colm+1<colm && grid[curr_row][curr_colm+1]==1 && arr[curr_row][curr_colm+1]!=2){
                arr[curr_row][curr_colm+1]= 2;
                q.push({{curr_row, curr_colm+1}, curr_time+1});
            }
            // row+1, col
            if (curr_row>=0 && curr_row+1<row && curr_colm>=0 && curr_colm<colm && grid[curr_row+1][curr_colm]==1 && arr[curr_row+1][curr_colm]!=2) {
                arr[curr_row+1][curr_colm]= 2;
                q.push({{curr_row+1, curr_colm}, curr_time+1});
            }
            // row-1, col
            if (curr_row-1>=0 && curr_row<row && curr_colm>=0 && curr_colm<colm && grid[curr_row-1][curr_colm]==1 && arr[curr_row-1][curr_colm]!=2) {
                arr[curr_row-1][curr_colm]= 2;
                q.push({{curr_row-1, curr_colm}, curr_time+1});
            }
            // row, col-1
            if (curr_row>=0 && curr_row<row && curr_colm-1>=0 && curr_colm<colm && grid[curr_row][curr_colm-1]==1 && arr[curr_row][curr_colm-1]!=2) {
                arr[curr_row][curr_colm-1]= 2;
                q.push({{curr_row, curr_colm-1}, curr_time+1});
            }
        }
        //check for -1 condition
        for (int i=0; i<row; i++) {
            for (int j=0; j<colm; j++) {
                if (grid[i][j]==1 && arr[i][j]!=2) return -1;
            }
        }
        return mnts;
    }
};