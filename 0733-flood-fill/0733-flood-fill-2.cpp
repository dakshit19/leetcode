class Solution {
public:
    void solve(queue<pair<int, int>> &q, vector<vector<int>> &grid,
               int color, vector<int> &dr, vector<int> &dc, int originalColor) {

        if (q.empty()) return;

        auto curr = q.front();
        q.pop();

        int row = curr.first;
        int colm = curr.second;

        grid[row][colm] = color;

        // check neighbours
        for (int i = 0; i < 4; i++) {
            int cr = row + dr[i];
            int cc = colm + dc[i];

            if (cr >= 0 && cr < grid.size() &&
                cc >= 0 && cc < grid[0].size() &&
                grid[cr][cc] == originalColor) {

                grid[cr][cc] = color;      // mark visited
                q.push({cr, cc});
            }
        }

        solve(q, grid, color, dr, dc, originalColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if (image[sr][sc] == color)
            return image;

        int originalColor = image[sr][sc];

        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {1, -1, 0, 0};

        queue<pair<int, int>> q;
        q.push({sr, sc});

        solve(q, image, color, dr, dc, originalColor);

        return image;
    }
};
