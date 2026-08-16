class Solution {
public:
    void solve(int n, vector<string> &res, string curr) {
        if (curr.size()==n){ //base case
            res.push_back(curr);
            return;
        }
        //take 1
        solve(n, res, curr+'1');
        //take 0
        if (curr.empty()||curr.back()=='1') {
            solve(n, res, curr+'0');
        }
        return;
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        solve(n, res, "");
        return res;
    }
};