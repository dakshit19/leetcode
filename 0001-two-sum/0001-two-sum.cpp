class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; //  element, idx
        int n= nums.size();
        vector<int> res(2);

        for (int i=0; i<n; i++) {
            int diff= target- nums[i];
            if (mp.find(diff)!= mp.end()) {
                res[0]= i;
                res[1]= mp[diff];
                break;
            } else mp[nums[i]]= i;
        }

        return res;
    }
};