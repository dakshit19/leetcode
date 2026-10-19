class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r=matrix.size(), c=matrix[0].size();
        vector<vector<int>> dp(r+1, vector<int> (c+1, 0));
        // 2d dp, dp[i][j]= max square length ending at (i,j)
        int res=0;
        for (int i=1; i<=r; i++) {
            for (int j=1;j<=c; j++) {
                if (matrix[i-1][j-1]=='1') {
                    dp[i][j]= min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]})+1;
                    res= max(res, dp[i][j]);
                }
            }
        }

        return res*res;
    }
};