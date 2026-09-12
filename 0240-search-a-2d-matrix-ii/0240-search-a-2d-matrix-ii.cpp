class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size(), col=matrix[0].size();

        for (int i=0; i<row; i++) {
            int l=0, h=col-1;
            while (l<=h) {
                int mid= l+ (h-l)/2;
                if (matrix[i][mid]== target) return true;
                else if (target> matrix[i][mid]) l=mid+1;
                else h= mid-1; 
            }
        }

        return false;
    }
};