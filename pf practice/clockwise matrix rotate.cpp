#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int matrix[n][n];

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse columns
    for (int j = 0; j < n; j++) {
        int top = 0, bottom = n - 1;
        while (top < bottom) {
            swap(matrix[top][j], matrix[bottom][j]);
            top++;
            bottom--;
        }
    }

    // Output rotated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
