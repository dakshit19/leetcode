class Solution {
public:
    void permut_helper(vector<vector<int>> &res, vector<int> curr, vector<int> nums) {
        if (nums.size()==0) {
            res.push_back(curr);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            curr.push_back(nums[i]);
            vector<int> remain= nums;
            remain.erase(remain.begin()+ i);

            permut_helper(res, curr, remain);
            //backtrack
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        int n=nums.size();

        permut_helper(res, curr, nums);
        return res;
    }
};