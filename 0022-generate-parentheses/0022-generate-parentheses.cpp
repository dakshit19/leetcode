class Solution {
public:
    void paraHelper(vector<string> &res, string curr, int open, int close, int n) {
        if (curr.size()==2*n && open==close) {
            res.push_back(curr);
            return;
        }
        // add open
        if (open<n) paraHelper(res, curr+'(',open+1, close, n);
        if (close<open) paraHelper(res, curr+')', open, close+1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr="";

        paraHelper(res, curr, 0, 0, n);

        return res;
    }
};