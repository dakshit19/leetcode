class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int n, int m) {

        vis[row][col] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                !vis[nr][nc] &&
                board[nr][nc] == 'O') {

                dfs(nr, nc, board, vis, n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse first and last column
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, board, vis, n, m);

            if (board[i][m - 1] == 'O' && !vis[i][m - 1])
                dfs(i, m - 1, board, vis, n, m);
        }

        // Traverse first and last row
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j])
                dfs(0, j, board, vis, n, m);

            if (board[n - 1][j] == 'O' && !vis[n - 1][j])
                dfs(n - 1, j, board, vis, n, m);
        }

        // Convert all unvisited O's into X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};