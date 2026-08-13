class Solution {
public:
    void permut_helper(vector<vector<int>> &res, vector<int> curr, int n, vector<int> nums) {
        if (curr.size()==n && nums.size()==0) {
            res.push_back(curr);
            return;
        } 
        for (int i = 0; i < nums.size(); i++) {
            
            // choose
            curr.push_back(nums[i]);

            // remove chosen element
            vector<int> remaining = nums;
            remaining.erase(remaining.begin() + i);

            // recurse
            permut_helper(res, curr, n, remaining);

            // undo choice
            curr.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        int n= nums.size();

        permut_helper(res, curr, n, nums);
        
        return res;
    }
};