class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=0, r=0;
        do {
            l= nums[l];
            r= nums[nums[r]];
        } while (l!=r);
        l=0;
        while (l!=r) {
            l= nums[l];
            r= nums[r];
        }
        return l;
    }
};