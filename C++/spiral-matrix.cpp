// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        
        int left = 0, right = matrix[0].size() - 1,
            top = 0, bottom = matrix.size() - 1;
        
        while (left <= right && top <= bottom) {
            for (int j = left; j <= right; ++j) {
                result.emplace_back(matrix[top][j]);
            }
            for (int i = top + 1; i < bottom; ++i) {
                result.emplace_back(matrix[i][right]);
            }
            for (int j = right; j >= left; --j) {
                if (top < bottom) {
                    result.emplace_back(matrix[bottom][j]);
                }
            }
            for (int i = bottom - 1; i > top; --i) {
                if (left < right) {
                    result.emplace_back(matrix[i][left]);
                }
            }
            ++left, --right, ++top, --bottom;
        }
        return result;
    }
};
