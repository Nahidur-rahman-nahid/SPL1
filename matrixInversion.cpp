#include "HeaderFiles.h"

using namespace std;

double determinant( vector<vector<double>>& A) {
    int n = A.size();
    if (n != A[0].size()) {
        throw runtime_error("Matrix is not square, and determinant cannot be calculated.");
    }

    if (n == 1) {
        return A[0][0];
    }

    if (n == 2) {
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }

    double det = 0.0;
    for (int i = 0; i < n; ++i) {
        vector<vector<double>> submatrix(n - 1, vector<double>(n - 1, 0.0));
        for (int j = 1; j < n; ++j) {
            int col = 0;
            for (int k = 0; k < n; ++k) {
                if (k != i) {
                    submatrix[j - 1][col] = A[j][k];
                    ++col;
                }
            }
        }
        det += (i % 2 == 0 ? 1.0 : -1.0) * A[0][i] * determinant(submatrix);
    }

    return det;
}




vector<vector<double>> matrixMultiply( vector<vector<double>>& A,  vector<vector<double>>& B) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();

    vector<vector<double>> result(n, vector<double>(m, 0.0));

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// Function to perform matrix inversion
vector<vector<double>> matrixInverse( vector<vector<double>>& A) {
    int n = A.size();
    if (n != A[0].size() || determinant(A) == 0.0) {
        throw runtime_error("Matrix is singular. The linear system may have no unique solution or infinitely many solutions.");
    }

    // Create an augmented matrix [A | I], where I is the identity matrix
    vector<vector<double>> augmented(n, vector<double>(2 * n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented[i][j] = A[i][j];
            if (i == j) {
                augmented[i][j + n] = 1.0;
            }
        }
    }

    // Perform row operations to get the inverse
    for (int i = 0; i < n; ++i) {
        // Make the diagonal element 1
        double pivot = augmented[i][i];
        for (int j = 0; j < 2 * n; ++j) {
            augmented[i][j] /= pivot;
        }

        // Make other rows' elements in the same column 0
        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = 0; j < 2 * n; ++j) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    vector<vector<double>> inverse(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = augmented[i][j + n];
        }
    }

    return inverse;
}

void matrixInversion(){
    int n;
    cout << "Enter the number of unknowns: ";
    cin >> n;

    // Define your coefficient matrix A and the right-hand side vector B
    vector<vector<double>> A(n, vector<double>(n, 0.0));
    vector<vector<double>> B(n, vector<double>(1, 0.0));

    cout << "Enter the coefficients of the linear system:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
        cout << "B[" << i << "]: ";
        cin >> B[i][0];
    }

    try {
        // Calculate the inverse of A

        vector<vector<double>> A_inverse = matrixInverse(A);


        vector<vector<double>> X = matrixMultiply(A_inverse, B);

        cout << "Matrix A:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << fixed << setprecision(2) << setw(8) << A[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Matrix A Inverse:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << fixed << setprecision(2) << setw(8) << A_inverse[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Matrix B:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << fixed << setprecision(2) << setw(8) << B[i][0] << endl;
        }

        cout << "Solution X:" << endl;
        for (int i = 0; i < n; ++i) {
            if(X[i][0] >= 0.0)
                cout << "x[" << i << "] = " << " " << X[i][0] << endl;
            else cout <<  "x[" << i << "] = " <<  X[i][0] << endl;
        }
    }catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

