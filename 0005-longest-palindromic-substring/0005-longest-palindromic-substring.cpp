class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        if (n<=1) return s;

        int maxLenPali=0;
        string res="";

        for (int i=0; i<n; i++) {
            // odd palindrome
            int left=i, right=i;
            int currLenPali= 0;
            while (left>=0 && right<n && s[left]==s[right]) { 
                left--;
                right++;
            }
            currLenPali= right-left-1;
            if (currLenPali > maxLenPali) {
                maxLenPali= currLenPali;
                res= "";
                for (int j=left+1; j<=right-1; j++) {
                    res+= s[j];
                }
            }

            // even palindrome
            left= i-1;
            right= i;
            currLenPali=0;
            while (left>=0 && right<n && s[left]==s[right]) { 
                left--;
                right++;
            }
            currLenPali= right-left-1;
            if (currLenPali > maxLenPali) {
                maxLenPali= currLenPali;
                res= "";
                for (int j=left+1; j<=right-1; j++) {
                    res+= s[j];
                }
            }
        }

        return res;
    }
};