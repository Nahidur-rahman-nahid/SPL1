#include"HeaderFiles.h"

void luDecompose(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U, vector<int>& P) {
    int n = A.size();

    // Initialize L and U matrices

    L.resize(n, vector<double>(n, 0.0));
    U.resize(n, vector<double>(n, 0.0));

    // Initialize permutation matrix P
    P.resize(n);
    for (int i = 0; i < n; ++i) {
        P[i] = i;
    }

    // Perform LU decomposition with partial pivoting
    for (int k = 0; k < n; ++k) {
        // Find the pivot row
        int pivotRow = k;
        double pivotValue = 0.0;
        for (int i = k; i < n; ++i) {
            if (abs(A[i][k]) > pivotValue) {
                pivotValue = abs(A[i][k]);
                pivotRow = i;
            }
        }

        // Check for singularity
        if (pivotValue < 1e-10) {
            throw runtime_error("Matrix is singular. LU decomposition failed.");
        }

        // Swap rows in A, L, and P
        swap(A[k], A[pivotRow]);
        swap(L[k], L[pivotRow]);
        swap(P[k], P[pivotRow]);

        // Calculate L and U elements
        U[k][k] = A[k][k];
        for (int i = k + 1; i < n; ++i) {
            L[i][k] = A[i][k] / U[k][k];
            U[k][i] = A[k][i];
        }

        // Update the remaining elements of A
        for (int i = k + 1; i < n; ++i) {
            for (int j = k + 1; j < n; ++j) {
                A[i][j] -= L[i][k] * U[k][j];
            }
        }
          cout << "Step " << k + 1 << ":" << endl;
          usleep(100000);
        cout << "Pivot Row: " << pivotRow << endl;
        usleep(10000);
        cout << "A matrix:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << fixed << setprecision(2) << setw(8) << A[i][j] << " ";
            }
            cout << endl;
        }
        usleep(1000000);
        cout << "L matrix:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << fixed << setprecision(2) << setw(8) << L[i][j] << " ";
            }
            cout << endl;
        }
        usleep(1000000);
        cout << "U matrix:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << fixed << setprecision(2) << setw(8) << U[i][j] << " ";
            }
            cout << endl;
        }
        usleep(1000000);
    }
}

vector<double> solveWithLU( vector<vector<double>>& A,vector<double>& B) {
    int n = A.size();
    vector<vector<double>> L, U;
    vector<int> P;

    // Perform LU decomposition
    luDecompose(A, L, U, P);

    // Apply permutation to B
    vector<double> PB(n);
    for (int i = 0; i < n; ++i) {
        PB[i] = B[P[i]];
    }

    // Solve Ly = PB using forward substitution
    vector<double> y(n, 0.0);
    for (int i = 0; i < n; ++i) {
        y[i] = PB[i];
        for (int j = 0; j < i; ++j) {
            y[i] -= L[i][j] * y[j];
        }
    }

    //Solve Ux = y using backward substitution
    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = y[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }

    return x;
}



void LU_DECOMPOSITION(){

    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n, 0.0));
    vector<double> B(n);

    cout << "Enter the coefficients of the linear system:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
        cin >> B[i];
    }

    try {
        vector<double> solution = solveWithLU(A, B);

        cout << "Solution:" << endl;
        for (int i = 0; i < n; ++i) {
            if(solution[i] >= 0)
                cout << "x[" << i << "] = " <<  " " << solution[i] << endl;
            else  cout << "x[" << i << "] = " << solution[i] << endl;
        }
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

}
