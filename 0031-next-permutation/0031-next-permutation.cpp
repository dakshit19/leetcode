class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        if (n==0 || n==1) return;
        int pivot=-1;
        //finding pivot
        for (int i=n-2; i>=0; i--) {
            if (nums[i]<nums[i+1]) {
                pivot= i;
                break;
            }
        }
        if (pivot==-1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        //finding next immediate
        for (int i=n-1; i>=pivot+1; i--) {
            if (nums[pivot]<nums[i]) {
                swap(nums[pivot], nums[i]);
                break;
            }
        }

        //reverse the remaining part
        reverse(nums.begin()+pivot+1, nums.end());
        return;
    }
};