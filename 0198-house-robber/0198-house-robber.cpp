class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1);
        dp[0]= 0;

        for (int i=1; i<=n; i++) {
            int notTake= dp[i-1], take=0;
            if (i<2) take= nums[i-1];
            else take= dp[i-2]+ nums[i-1];
            dp[i]= max(take, notTake);
        }

        return dp[n];
    }
};