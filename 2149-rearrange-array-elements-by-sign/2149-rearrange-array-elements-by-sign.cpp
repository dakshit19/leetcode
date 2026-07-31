class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i]>0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        //pushing the result
        vector<int> res;
        int p=0, n=0;
        for (int i=0; i<nums.size(); i++) {
            if (p<pos.size() && i%2==0) {
                res.push_back(pos[p]);
                p++;
            } else if (n<neg.size() && i%2==1) {
                res.push_back(neg[n]);
                n++;
            }
        }

        return res;
    }
};