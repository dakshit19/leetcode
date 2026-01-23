class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st=0, end= nums.size()-1;
        int mid=-1;

        while(st<=end){
            mid= st+ (end-st)/2;

            int left  = (mid == 0) ? INT_MIN : nums[mid - 1];
            int right = (mid == end) ? INT_MIN : nums[mid + 1];

            if ((nums[mid]>left) && (nums[mid]>right)) return mid;
            else if (right>nums[mid]){
                st= mid+1;
            } else end=mid-1;
        }

        return mid;
    }
};