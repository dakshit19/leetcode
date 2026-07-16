class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n= nums.size();
        int ans= INT_MIN;
        int maxPrefix= INT_MIN;

        for (int j=k; j<n; j++){
            maxPrefix= max(maxPrefix, nums[j-k]);
            ans= max(ans, maxPrefix+nums[j]);
        }        

        return ans;
    }
};