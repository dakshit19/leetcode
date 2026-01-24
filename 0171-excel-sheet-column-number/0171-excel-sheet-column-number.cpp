class Solution {
public:
    long long titleToNumber(string columnTitle) {
        long long res = 0;

        for (char c : columnTitle) {
            int val = c - 'A' + 1;
            res = res * 26 + val;
        }

        return res;
    }
};

