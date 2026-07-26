class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1=0, cand2=0;
        int count1=0, count2=0;
        int n= nums.size();

        for (int i=0; i<n; i++) {
            if (nums[i]==cand1) count1++;
            else if (nums[i]==cand2) count2++;
            else if (count1==0 && nums[i]!=cand2) {
                count1=1;
                cand1= nums[i];
            } else if (count2==0 && nums[i]!=cand1) {
                cand2= nums[i];
                count2=1;
            } else {
                count1--;
                count2--;
            }
        }        

        vector<int> res;
        int countcand1=0, countcand2=0;
        for (int i=0; i<n; i++) {
            if (nums[i]==cand1) countcand1++;
            else if (nums[i]==cand2) countcand2++;
        }

        if (countcand1> (n/3)) res.push_back(cand1);
        if (countcand2> (n/3)) res.push_back(cand2);
        return res;
    }
};