class Solution {
public:
    void subshelper(const vector<int> &nums, vector<vector<int>> &res, vector<int> curr, int idx) {
        if (idx== nums.size()) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        subshelper(nums, res, curr, idx+1);

        //backtrack
        curr.pop_back();
        while (idx+1<nums.size() && nums[idx]== nums[idx+1]) {
            idx++;
        }
        subshelper(nums, res, curr, idx+1);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        subshelper(nums, res, curr, 0);
        return res;
    }
};