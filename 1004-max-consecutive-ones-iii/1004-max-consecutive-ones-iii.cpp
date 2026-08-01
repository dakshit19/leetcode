class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n= nums.size(), maxlen=0, l=0, r=0, zadded=0;
        while (r<n) {
            if (nums[r]==1) r++;
            else if (nums[r]==0 && zadded<k) {
                r++;
                zadded++;
            } else {
                while (nums[l]!=0) l++;
                l++;
                zadded--;
            }

            maxlen= max(maxlen, r-l);
        }
        return maxlen;
    }
};