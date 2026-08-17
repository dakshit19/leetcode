class Solution {
public:
    void combSumhelper(vector<vector<int>> &res, const vector<int> &nums, const int targ, int sum, int idx, vector<int> &subs) {
        if (sum>targ) return;
        if (idx== nums.size()) { //subsequence found
            if (sum== targ){
                res.push_back(subs);
            }
            return;
        }

        subs.push_back(nums[idx]);
        sum+= nums[idx];
        combSumhelper(res, nums, targ, sum, idx, subs); //take

        subs.pop_back();
        sum-= nums[idx];
        combSumhelper(res, nums, targ, sum, idx+1, subs); //not take     
        return;   
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        combSumhelper(res, candidates, target, 0, 0, curr);
        return res;
    }
};