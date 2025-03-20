#include <iostream>
using namespace std;

int main() {
    int a[10][10], transpose[10][10], r, c;
    
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    // Assigning elements to the matrix
    cout << "\nEnter matrix elements:\n";
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            cout << "Enter element a" << i + 1 << j + 1 << ": ";
            cin >> a[i][j];
        }

    // Printing the matrix a[][]
    cout << "\nEntered matrix: \n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << a[i][j] << "  ";
            if (j == c - 1)
                cout << endl;
        }
    }

    // Computing the transpose
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            transpose[j][i] = a[i][j];
        }

    // Printing the transpose
    cout << "\nTranspose of the matrix:\n";
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            cout << transpose[i][j] << "  ";
            if (j == r - 1)
                cout << endl;
        }
    }
    
    return 0;
}
