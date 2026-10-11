class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        // Case 1: Exclude the last house
        vector<int> dp1(n, 0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i <= n - 2; i++) {
            int take = dp1[i - 2] + nums[i];
            int notTake = dp1[i - 1];
            dp1[i] = max(take, notTake);
        }
        int res1 = dp1[n - 2];

        // Case 2: Exclude the first house
        vector<int> dp2(n, 0);
        dp2[1] = nums[1];

        for (int i = 2; i <= n - 1; i++) {
            int take = dp2[i - 2] + nums[i];
            int notTake = dp2[i - 1];
            dp2[i] = max(take, notTake);
        }

        int res2 = dp2[n - 1];

        return max(res1, res2);
    }
};