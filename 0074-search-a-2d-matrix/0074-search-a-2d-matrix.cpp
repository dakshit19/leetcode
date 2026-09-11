class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size(), col= matrix[0].size();
        //find row
        int l=0, h=row-1, rowidx=-1;
        while (l<=h) {
            int mid= l+ (h-l)/2;
            if (target>= matrix[mid][0]) {
                rowidx= mid;
                l=mid+1;
            }
            else h= mid-1;
        }

        if (rowidx==-1) return false;

        //matrix[rowidx][]
        l=0, h=col-1;
        while (l<=h) {
            int m= l+ (h-l)/2;
            if (target== matrix[rowidx][m]) return true;
            else if (target> matrix[rowidx][m]) l= m+1;
            else h= m-1;
        }

        return false;
    }
};