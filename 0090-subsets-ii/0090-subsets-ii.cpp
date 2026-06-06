class Solution {
public:
    bool isexist(vector<int> &ans, vector<vector<int>> &res){
        return find(res.begin(), res.end(), ans) != res.end();
    }

    void fun(vector<vector<int>> &result, vector<int> &ans, vector<int> &nums, int i){
        if (i==nums.size()){
            if (!isexist(ans, result)){
                result.push_back(ans);
            }
            return;
        }
        
        //include
        ans.push_back(nums[i]);
        fun(result, ans, nums, i+1);

        ans.pop_back(); //backtracking
        fun(result, ans, nums, i+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        sort(nums.begin(), nums.end());

        fun(result, ans, nums, 0);
        return result;
    }
};