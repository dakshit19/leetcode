class Solution {
public:

    int maxIncreasingSubarrays(vector<int>& nums) {
        int l=0, n=nums.size(), res=0;
        int prevLen=0;
        while (l<n) {
            int h=l;
            while (h+1<n && nums[h+1]>nums[h]) h++;
            int currLen= h-l+1;
            auto fun=[&]() {
                return max(currLen/2, min (prevLen,currLen));
            };
            res= max(res, fun());
            prevLen= currLen;
            l=h+1;
        }
        return res;
    }
};