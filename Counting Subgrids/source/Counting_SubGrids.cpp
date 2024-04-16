#include <bits/stdc++.h>
using namespace std;

int counting_subgrid(vector<vector<int>>& matrix) {
    int n = matrix.size(); // Number of rows
    int m = matrix[0].size(); // Number of columns

    vector<int> row(n); // Vector to store integer representation of each row

    // Convert each row of the matrix to integer representation
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            row[i] |= matrix[i][j] << (m - j); // Set the corresponding bit based on matrix element
        }
    }

    int ans = 0; // Variable to store the count of subgrids

    // Iterate through each pair of rows
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Calculate the number of common set bits between the two rows
            int bits = __builtin_popcount(row[i] & row[j]);
            // Calculate the number of subgrids formed by the pair of rows and add it to 'ans'
            int count = bits * (bits - 1) / 2;
            ans += count;
        }
    }

    return ans; // Return the count of subgrids
}int main() {
    ifstream cin("input2.txt"); // Open input file
    ofstream cout("../output/output2.txt"); // Open output file

    int n; // Number of rows (and columns)
    cin >> n; // Read the number of rows

    vector<vector<int>> matrix(n, vector<int>(n)); // Define and initialize square matrix

    // Read input from file
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j]; // Read each element of the matrix
        }
    }

    // Call counting_subgrid function with the input matrix and store the result
    int result = counting_subgrid(matrix);

    // Write the result to the output file
    cout << result << endl;

    return 0;
}
