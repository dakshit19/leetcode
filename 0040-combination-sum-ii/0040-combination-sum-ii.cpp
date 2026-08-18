class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> subs, const vector<int> &nums, int targ, int idx, int sum) {
        if (sum > targ) return;
        if (sum == targ) {
            res.push_back(subs);
            return;
        }
        if (idx == nums.size()) return;

        subs.push_back(nums[idx]);
        helper(res, subs, nums, targ, idx + 1, sum + nums[idx]);//take

        subs.pop_back(); //not take
        idx++;
        // skip duplicate values
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }
        helper(res, subs, nums, targ, idx, sum);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        helper(res, curr, candidates, target, 0, 0);
        return res;
    }
};