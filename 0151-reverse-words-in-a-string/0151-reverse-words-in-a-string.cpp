class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0;
        string res = "";

        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i >= n) break;

            int j = i;
            string word = "";

            while (j < n && s[j] != ' ') {
                word += s[j];
                j++;
            }

            reverse(word.begin(), word.end());

            if (!res.empty()) res += " ";
            res += word;

            i = j;
        }

        return res;
    }
};
