#include"HeaderFiles.h"
void gaussJordan(){

    vector<vector<double>> matrix ;
    int  numRows,numCols;
    cout << "enter the number of unknowns( >= 2): ";
    cin >> numRows;
    cout << "Equation's will be in coefficient and constant form." << endl;
    cout << "Example:(ax + by + cz = d) input : a b c d\n";

    //freopen("linearSystemEquations.txt","r",stdin);

    numCols = numRows+1;

    double val;
    for(int i = 0; i < numRows; i++)
    {
        cout << "enter the "<<(i+1) << " equation: ";
        vector<double>row;
        for(int j = 0; j < numCols; j++)
        {
            cin >> val;
            row.push_back(val);
        }
        matrix.push_back(row);
    }
        numRows = matrix.size();
        numCols = matrix[0].size();

    for (int i = 0; i < numRows; ++i) {
        // Display the current step number
        cout << "Step " << i + 1 << ":" << endl;
        cout << "Initial state of Matrix:" << endl;
        printMatrix(matrix);

        // Partial pivoting: Find the row with the maximum pivot value
        int maxRow = i;
        for (int j = i + 1; j < numRows; ++j) {
            if (abs(matrix[j][i]) > abs(matrix[maxRow][i])) {
                maxRow = j;
            }
        }

        if (maxRow != i) {
            swap(matrix[i], matrix[maxRow]);
            cout << "Swapping rows " << i << " and " << maxRow << ":" << endl;
            printMatrix(matrix);
        }

          if (abs(matrix[i][i]) < 1e-10) {
            cout << "Zero pivot encountered. Swapping rows to avoid division by zero." << endl;
            bool swapped = false;
            for (int j = i + 1; j < numRows; ++j) {
                if (abs(matrix[j][i]) > 1e-10) {
                    swap(matrix[i], matrix[j]);
                    cout << "Swapping rows " << i << " and " << j << ":" << endl;
                    swapped = true;
                    break;
                }
            }
            if (!swapped) {
                cout << "No unique solution exists." << endl;
                return; // Exit the function if no unique solution exists
            }
         }

        double pivot = matrix[i][i];

        // Scale the pivot row
        for (int j = 0; j < numCols; ++j) {
            double tmp = matrix[i][j] / pivot;
            if(tmp == -0.00)matrix[i][j] = 0.00;
            else
                matrix[i][j] /= pivot;
        }

        // Eliminate other rows
        for (int j = 0; j < numRows; ++j){
            if (j != i) {
                double factor = matrix[j][i];
                for (int k = 0; k < numCols; ++k) {
                    matrix[j][k] -= factor * matrix[i][k];
                    if(matrix[j][k] == -0.00)matrix[j][k] = 0.00;
                }
            }
        }

        // Display the matrix after the current step
        cout << "Matrix after Step " << i + 1 << ":" << endl;
        usleep(1000000);
        printMatrix(matrix);
    }
    cout << "solution:\n";
    for(int i = 0;i < numRows;i++){
        cout << "x[i] : ";
        if( matrix[i][numCols - 1] >= 0)cout << " " << matrix[i][numCols-1] << endl;
        else cout << matrix[i][numCols-1] << endl;
    }

}
