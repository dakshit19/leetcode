class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int n= nums.size();
        
        while (i<n) {
            //red
            int j=0;
            while (j<n) {
                if (nums[j]==0) {
                    swap(nums[j], nums[i]);
                    i++;
                }
                j++;
            }
            j=0;
            while (j<n) {
                if (nums[j]==1) {
                    swap(nums[j], nums[i]);
                    i++;
                }
                j++;
            }
            j=0;
            while (j<n) {
                if (nums[j]==2) {
                    swap(nums[j], nums[i]);
                    i++;
                }
                j++;
            }
        }
    }
};