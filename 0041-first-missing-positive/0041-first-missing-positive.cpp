class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n= nums.size();
        bool has1= false;

        for (int &num: nums) {
            if (num==1) has1= true;
            if (num>n || num<=0) num= 1; //change out of bound to 1
        }
        if (!has1) return 1;
        
        for (int i=0; i<n; i++) {
            int idx= abs(nums[i])-1;
            if (nums[idx]<0) continue;
            nums[idx]*=-1;
        }

        for (int i=0; i<n; i++) {
            if (nums[i]>0) return i+1;
        }
        return n+1;
    }
};