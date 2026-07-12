class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        int maxLen= 0;

        for (int start=0; start<n; start++) {
            string curr= "";
            int currLen=0;
            map <char, int> mp;

            for (int end= start; end<n; end++) {
                if (mp.find(s[end]) == mp.end()) {
                    curr+= s[end];
                    mp.insert({s[end], 1});
                    currLen++;
                }  else break;
            }

            maxLen= max(maxLen, currLen);
        }

        return maxLen;
    }
};