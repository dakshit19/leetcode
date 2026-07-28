class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp;

        // Count frequency
        for (char ch : s) {
            mp[ch]++;
        }

        string left = "";
        string middle = "";

        for (auto it : mp) {
            char ch = it.first;
            int freq = it.second;

            // Add half of the characters
            for (int i = 0; i < freq / 2; i++) {
                left += ch;
            }

            // Odd frequency character goes in the middle
            if (freq % 2 == 1) {
                middle += ch;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};