class Solution {
public:
    void fun(vector<int> &arr, vector<vector<int>> &final, vector<int> &ans, int i){
        if ( i== arr.size()){
            final.push_back(ans);
            return;
        }

        //include 
        ans.push_back(arr[i]);
        fun(arr, final, ans, i+1);
        //exclude
        ans.pop_back();
        fun(arr, final, ans, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;

        fun(nums, result, ans, 0);

        return result;
    }
};