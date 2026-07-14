class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n= firstList.size(); // list a size
        int m= secondList.size(); // list b size
        int i=0, j=0; // i for list A, j for list B

        while (i<n && j<m) {
            int s1= firstList[i][0];
            int s2= secondList[j][0];
            int e1= firstList[i][1];
            int e2= secondList[j][1];

            int start = max(s1, s2); 
            int end = min(e1, e2);

            if (start <= end) { //intersecting case
                res.push_back({start, end});
            }
            if (e1 < e2) {
                i++;
            } else j++;
        }

        return res;
    }
};