class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        vector<int> res;

        int layers = (min(rows, columns) + 1) / 2;

        for (int k = 0; k < layers; k++) {

            // top row
            for (int i = k; i < columns - k; i++)
                res.push_back(matrix[k][i]);

            // right column
            for (int i = k + 1; i < rows - k; i++)
                res.push_back(matrix[i][columns - k - 1]);

            // bottom row
            if (rows - k - 1 != k) {
                for (int i = columns - k - 2; i >= k; i--)
                    res.push_back(matrix[rows - k - 1][i]);
            }

            // left column
            if (columns - k - 1 != k) {
                for (int i = rows - k - 2; i > k; i--)
                    res.push_back(matrix[i][k]);
            }
        }

        return res;
    }
};