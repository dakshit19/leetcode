class Solution {
public:
    void helper(int n, vector<string> &res, string curr) {
        if (curr.size()==n) {
            res.push_back(curr);
            return;
        }

        //take 1
        helper(n, res, curr+'1');
        //check if valid then insert 0
        if (curr.empty()||curr.back()=='1')
            helper(n, res, curr+'0');
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        string curr="";

        helper(n, res, curr );
        return res;
    }
};