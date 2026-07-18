class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    bool firstRowZero = false;
    bool firstColZero = false;

    // Check whether the first row originally contains a zero
    for (int c = 0; c < cols; c++) {
        if (matrix[0][c] == 0) {
            firstRowZero = true;
        }
    }

    // Check whether the first column originally contains a zero
    for (int r = 0; r < rows; r++) {
        if (matrix[r][0] == 0) {
            firstColZero = true;
        }
    }

    // Use the first row and column as markers
    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            if (matrix[r][c] == 0) {
                matrix[r][0] = 0; // mark this row
                matrix[0][c] = 0; // mark this column
            }
        }
    }

    // Zero cells based on the markers
    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                matrix[r][c] = 0;
            }
        }
    }

    // Handle the first row
    if (firstRowZero) {
        for (int c = 0; c < cols; c++) {
            matrix[0][c] = 0;
        }
    }

    // Handle the first column
    if (firstColZero) {
        for (int r = 0; r < rows; r++) {
            matrix[r][0] = 0;
        }
    }
}
};
