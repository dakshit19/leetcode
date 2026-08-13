class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> curr, vector<int> nums) {
        if (nums.empty()) {
            res.push_back(curr);
            return;
        }
        unordered_set<int> used;
        for (int i=0; i<nums.size(); i++) {
            if (used.find(nums[i])==used.end()) {
                vector<int> remain= nums;
                curr.push_back(nums[i]);
                used.insert(nums[i]);
                remain.erase(remain.begin()+ i);
                helper(res, curr, remain);
                //backtrack
                curr.pop_back();
            } 
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        helper(res, curr, nums);
        return res;   
    }
};