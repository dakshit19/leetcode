class Solution {
public:

    int leftocc(vector<int> nums, int target){
        int l=0, h=nums.size()-1;
        int res=-1;

        while(l<=h){
            int mid = l+ (h-l)/2;
            if (nums[mid]==target) {
                res=mid;
                h=mid-1; 
            } else if (nums[mid]>target) h= mid-1;
            else l= mid+1;
        }

        return res;
    }

    int rightocc(vector<int> nums, int target){
        int l=0, h=nums.size()-1;
        int res=-1;

        while(l<=h){
            int mid = l+ (h-l)/2;
            if (nums[mid]==target) {
                res=mid;
                l=mid+1; 
            } else if (nums[mid]>target) h= mid-1;
            else l= mid+1;
        }

        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {leftocc(nums, target), rightocc(nums, target)};
    }
};