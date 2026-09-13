class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;

        int l=0, h=nums.size()-1;
        while (l<=h) {
            int mid= l+ (h-l)/2;
            if (nums[mid]== target) return true;
            // duplicate
            if(nums[l]==nums[mid] && nums[mid]==nums[h]) {
                l++;
                h--;
            } else if (nums[l]<=nums[mid]) { //left sorted
                if (nums[l]<=target && target<nums[mid]) h=mid-1;
                else l=mid+1;
            } else { //right sorted
                if (nums[mid]<target && target<=nums[h]) l=mid+1;
                else h= mid-1;
            }
        }        
        return false;
    }
};