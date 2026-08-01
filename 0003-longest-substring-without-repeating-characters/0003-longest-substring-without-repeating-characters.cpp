class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        if(n==0) return 0;

        int count=1, maxCount=1, i=0;
        unordered_set<int> st;
        st.insert(s[0]);

        for (int j=1; j<n; j++) {
            if (st.find(s[j])==st.end()) {
                count++;
                maxCount= max(maxCount, count);
                st.insert(s[j]);
            } else {
                while (st.find(s[j])!= st.end()) {
                    st.erase(s[i]);
                    i++;
                    count--;
                }
                st.insert(s[j]);
                count++;
            }
        } 

        return maxCount;
    }
};