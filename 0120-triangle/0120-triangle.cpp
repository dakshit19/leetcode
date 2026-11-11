class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, 1e9));
        dp[0][0]= triangle[0][0];

        for (int i=1; i<n; i++) {
            for (int j=0;j<=i; j++) {
                int up= (j<i)? up=dp[i-1][j] : 1e9;
                int left= (j>0)? left= dp[i-1][j-1] : 1e9;
                dp[i][j]= triangle[i][j] + min(up, left); 
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};