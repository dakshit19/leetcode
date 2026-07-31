class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //initializing
        int n= nums.size();
        if (n==0) return 0;
        int count=1;
        unordered_set<int> s (nums.begin(), nums.end());

        for (auto it: s) {
            if (s.find(it-1)!=s.end()) continue;
            int currcount=1;
            int k= it;
            while(s.find(k+1)!=s.end()) {
                currcount++;
                k++;
            }
            count= max(count, currcount);
        } 

        return count;
    }
};