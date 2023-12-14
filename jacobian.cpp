#include "HeaderFiles.h"

void jacobiMethod(){
    vector<vector<double>> matrix;
    int numRows, numCols;

    cout << "Enter the number of unknowns (>= 2): ";
    cin >> numRows;
    cout << "Equations will be in coefficient and constant form." << endl;
    cout << "Example: (ax + by + cz = d) input: a b c d\n";

    numCols = numRows + 1;
    double val;

    for (int i = 0; i < numRows; i++) {
        cout << "Enter the " << (i + 1) << " equation: ";
        vector<double> row;
        for (int j = 0; j < numCols; j++) {
            cin >> val;
            row.push_back(val);
        }
        matrix.push_back(row);
    }

    numRows = matrix.size();
    numCols = matrix[0].size();

    // Initialize the initial guess for solutions
    vector<double>initialGuess(numRows, 0.0);

    // Setting the number of iterations and convergence criteria
    int maxIterations = 1000;
    double tolerance = 1e-6;

    for (int iteration = 1; iteration <= maxIterations; iteration++) {
        vector<double> newGuess(numRows, 0.0);

        for (int i = 0; i < numRows; i++) {
            double sum = matrix[i][numCols - 1];
            for (int j = 0; j < numRows; j++) {
                if (i != j) {
                    sum -= matrix[i][j] * initialGuess[j];
                }
            }
            newGuess[i] = sum / matrix[i][i];
        }


        bool converged = true;
        for (int i = 0; i < numRows; i++) {
            if (abs(newGuess[i] - initialGuess[i]) > tolerance) {     //whether it is converged or not
                converged = false;
                break;
            }
        }


        initialGuess = newGuess;    // Update the initial guess here

        cout << "Iteration " << iteration << ":" << endl;
        cout << "Solution: ";
        for (int i = 0; i < numRows; i++) {
            cout << "x[" << i << "] = " << initialGuess[i] << "  ";
        }
        cout << endl;

        if (converged) {
            cout << "Converged after " << iteration << " iterations." << endl;
            break;
        }
    }

    cout << "Final Solution:" << endl;
    for (int i = 0; i < numRows; i++) {
        cout << "x[" << i << "] = " << initialGuess[i] << endl;
    }
}

