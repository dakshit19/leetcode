class Solution {
public:
    //const int MOD= 2* (1e9);
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));//2d dp
        dp[0][0]=1;
        for (int i=0;i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i==0 && j==0) continue;
                int top=0, left=0;
                if (i>0) top= dp[i-1][j];
                if (j>0) left= dp[i][j-1];
                dp[i][j]= (top+left);
            }
        }
        return dp[m-1][n-1];
    }
};