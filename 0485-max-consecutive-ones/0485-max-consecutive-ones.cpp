class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int res=0, i=0, currCount=0;

        while (i<n) {
            if (nums[i]==0) {
                res= max(res, currCount);
                currCount=0;
            } else {
                currCount++;
            }
            i++;
        }

        return max(res, currCount);
    }
};