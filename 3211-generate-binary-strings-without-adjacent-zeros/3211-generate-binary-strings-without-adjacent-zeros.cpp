class Solution {
public:
    void solve(int n, vector<string> &res, string &curr) {
        if (curr.size()==n){ //base case
            res.push_back(curr);
            return;
        }
        //take 1
        curr.push_back('1');
        solve(n, res, curr);
        curr.pop_back(); //backtrack
        //take 0
        if (curr.empty()||curr.back()=='1') {
            curr.push_back('0');
            solve(n, res, curr);
            curr.pop_back(); //backtrack
        }
        return;
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        string curr="";
        solve(n, res, curr);
        return res;
    }
};