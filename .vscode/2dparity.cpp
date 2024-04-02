#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the parity bit for a row or column
int calculateParity(const vector<int>& data) {
    int parity = 0;
    for (int bit : data)
        parity ^= bit;
    return parity;
}

// Function to add parity bits to each row and column
void addParity(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Add parity bit for each row
    for (int i = 0; i < rows; ++i) {
        int row_parity = calculateParity(matrix[i]);
        matrix[i].push_back(row_parity);
    }

    // Add parity bit for each column
    for (int j = 0; j < cols + 1; ++j) {
        vector<int> column_data;
        for (int i = 0; i < rows; ++i) {
            column_data.push_back(matrix[i][j]);
        }
        int col_parity = calculateParity(column_data);
        matrix.push_back({col_parity});
    }
}

// Function to check parity bits and correct errors if possible
bool checkParity(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> row_parity;
    vector<int> col_parity;

    // Extract row and column parity bits
    for (int i = 0; i < rows - 1; ++i) {
        row_parity.push_back(matrix[i].back());
    }
    for (int j = 0; j < cols - 1; ++j) {
        col_parity.push_back(matrix[rows - 1][j]);
    }

    // Calculate actual row and column parity and compare with received parity
    for (int i = 0; i < rows - 1; ++i) {
        int actual_row_parity = calculateParity(matrix[i]);
        if (actual_row_parity != row_parity[i]) {
            cout << "Error detected in row " << i << endl;
            return false;
        }
    }

    for (int j = 0; j < cols - 1; ++j) {
        vector<int> column_data;
        for (int i = 0; i < rows - 1; ++i) {
            column_data.push_back(matrix[i][j]);
        }
        int actual_col_parity = calculateParity(column_data);
        if (actual_col_parity != col_parity[j]) {
            cout << "Error detected in column " << j << endl;
            return false;
        }
    }

    cout << "No errors detected" << endl;
    return true;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 1, 1}
    };

    cout << "Original Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int bit : row) {
            cout << bit << " ";
        }
        cout << endl;
    }

    addParity(matrix);

    cout << "Matrix with Parity Bits:" << endl;
    for (const auto& row : matrix) {
        for (int bit : row) {
            cout << bit << " ";
        }
        cout << endl;
    }

    // Simulate transmission - flipping some bits
    matrix[0][0] = 0; // introducing an error

    cout << "Matrix after transmission:" << endl;
    for (const auto& row : matrix) {
        for (int bit : row) {
            cout << bit << " ";
        }
        cout << endl;
    }

    cout << "Checking Parity:" << endl;
    checkParity(matrix);

    return 0;
}
