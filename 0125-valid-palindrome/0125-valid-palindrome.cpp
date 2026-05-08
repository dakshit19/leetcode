class Solution {
public:
    bool solve(int left, int right, string &s) {
        // base case
        if (left >= right) return true;

        // skip non-alphanumeric from left
        if (!isalnum(s[left]))
            return solve(left + 1, right, s);

        // skip non-alphanumeric from right
        if (!isalnum(s[right]))
            return solve(left, right - 1, s);

        // compare characters (case-insensitive)
        if (tolower(s[left]) != tolower(s[right]))
            return false;

        // move both pointers
        return solve(left + 1, right - 1, s);
    }

    bool isPalindrome(string s) {
        return solve(0, s.length() - 1, s);
    }
};