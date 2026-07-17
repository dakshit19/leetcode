class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n= nums.size();
        map<int, int> mp; //key= nums, value= count

        for (int i=0; i<n; i++) {
            if (mp.find(nums[i])!= mp.end()) mp[nums[i]]++;
            else mp.insert({nums[i], 1}); 
        }
        for (auto nums: mp) {
            if (nums.second == 1) return nums.first;
        }   
        
        return -1;     
    }
};