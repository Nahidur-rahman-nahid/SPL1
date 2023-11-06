#include"HeaderFiles.h"
vector<double> solveLinearSystem( vector<vector<double>>& A,  vector<double>& B){
    int n = A.size();
    vector<double> solution(n);

    // Calculate the determinant of the coefficient matrix A  which is previously created
    double detA = determinant(A);

    if (abs(detA) < 1e-10) {
        throw runtime_error("The coefficient matrix is singular. The system may have no unique solution or infinitely many solutions.");
    }
    // here goes the creamer's rule
    for (int i = 0; i < n; ++i) {
        vector<vector<double>> Ai = A;
          for(int j = 0;j < n;j++)
            Ai[j][i] = B[j];

        solution[i] = determinant(Ai) / detA;

    }

    return solution;
}

void creamerRule(){

    int n;
    cout << "Enter the number of unknowns: ";
    cin >> n;

    // Define your coefficient matrix A and the right-hand side vector B

    vector<vector<double>> A(n, vector<double>(n, 0.0));
    vector<double> B(n);

    cout << "Enter the coefficients of the linear system:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
        cout << "B[" << i << "]: ";
        cin >> B[i];
    }

    try {

        vector<double> solution = solveLinearSystem(A, B);

        cout << "Coefficient Matrix A:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << fixed << setprecision(2) << setw(8) << A[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Right-hand Side Vector B:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << fixed << setprecision(2) << setw(8) << B[i] << endl;
        }

        cout << "Solution X:" << endl;
        for (int i = 0; i < n; ++i) {
            if(solution[i] >= 0.0)
                cout << "x[" << i << "] = " << " " << solution[i] << endl;
            else  cout << "x[" << i << "] = " << solution[i] << endl;
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

}
