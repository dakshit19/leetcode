class Solution {
public:
    void solve(vector<vector<int>> &img, int r, int c, int oldcolor, int color) {
        int n= img.size();
        int m= img[0].size();
        // boundary check
        if (r<0 || r>=n || c<0 || c>=m) return;

        if (img[r][c]!= oldcolor) return;
        if (img[r][c]==color) return;

        img[r][c]= color;

        solve(img, r-1, c, oldcolor, color);
        solve(img, r+1, c, oldcolor, color);
        solve(img, r, c-1, oldcolor, color);
        solve(img, r, c+1, oldcolor, color);
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor= image[sr][sc];
        if (oldcolor==color) return image;

        solve(image, sr, sc, oldcolor, color);

        return image;
    }
};