class Solution {
public:
    void paranth_helper(vector<string> &res, int n, string curr, int open, int close) {
        if (close>open) return;
        if (close==open && curr.size()==2*n) {
            res.push_back(curr);
            curr="";
            return;
        }
        if (open<n) paranth_helper(res, n, curr+"(", open+1, close); //adding open
        if (close<open) paranth_helper(res, n, curr+")", open, close+1); //adding close
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;

        paranth_helper(res, n, "", 0, 0);
        return res;
    }
};