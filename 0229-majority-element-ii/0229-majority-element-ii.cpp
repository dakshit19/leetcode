class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int freq_cand1=0, cand1;
        int freq_cand2=0, cand2;
        
        for (int i=0; i<n; i++) {
            if (nums[i]==cand1) freq_cand1++;
            else if (nums[i]==cand2) freq_cand2++;
            else if (freq_cand1==0 && nums[i]!=cand2) {
                cand1= nums[i];
                freq_cand1=1;
            } 
            else if (freq_cand2==0 && nums[i]!=cand1) {
                cand2= nums[i];
                freq_cand2=1;
            } else {
                freq_cand1--;
                freq_cand2--;               
            }
        }

        int count_cand1=0, count_cand2=0;
        for (int i=0; i<n; i++) {
            if (nums[i]==cand1) count_cand1++;
            else if (nums[i]==cand2) count_cand2++;
        }

        vector<int> res;
        if (count_cand1> (n/3)) res.push_back(cand1);
        if (count_cand2> (n/3)) res.push_back(cand2);
        return res;        
    }
};