class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value, index

        for (int i=0; i<nums.size();  i++) {
            int diff= target- nums[i];
            
            if (mp.find(diff)!=mp.end()) return {i, mp[diff]};
            else mp.insert({nums[i], i});
        }

        return {-1, -1};
    }
};