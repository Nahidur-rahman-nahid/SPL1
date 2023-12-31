#include "HeaderFiles.h"
#include<bits/stdc++.h>
#include<windows.h>
#include <unistd.h>

using namespace std;

void printMatrix(vector<vector<double>>&matrix){

    for(int i = 0;i < matrix.size();i++){
        for(int j = 0;j < matrix[0].size();j++){
            if(matrix[i][j] >= 0.0)
                cout << " " << fixed << setprecision(2) << matrix[i][j] << "  ";
            else cout << fixed << setprecision(2) << matrix[i][j] << "  ";
        }
        cout << endl;
    }

}

void swapRows(vector<vector<double>>&matrix, int row1, int row2)
{
    int numCols = matrix[0].size();
    for (int j = 0; j < numCols; j++)
    {
        double temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

vector<double> backSubstitution( vector<vector<double>>& matrix)
{
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    vector<double> solution(numRows);

    for (int i = numRows - 1; i >= 0; --i)
    {
        double sum = 0;
        for (int j = i + 1; j < numCols - 1; ++j)
        {
            sum += matrix[i][j] * solution[j];
        }
        solution[i] = (matrix[i][numCols - 1] - sum) / matrix[i][i];
    }
    return solution;
}

void gaussianElimination()
{
    vector<vector<double>> matrix ;
    int  numRows,numCols;
    cout << "enter the number of unknowns( >= 2): ";

    cin >> numRows;
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

     cout << "Original Matrix:" << endl;
     printMatrix(matrix);

     check();

     numRows = matrix.size();
     numCols = matrix[0].size();

    for (int i = 0; i < numRows - 1; ++i)
    {
        // Partial pivoting: Find the row with the maximum pivot value
        int maxRow = i;
        for(int j = i + 1; j < numRows; ++j)
        {
            if (abs(matrix[j][i]) > abs(matrix[maxRow][i]))
            {
                maxRow = j;
            }
        }

        // Swap current row with the row containing the maximum pivot value
        if (maxRow != i)
        {
            swapRows(matrix,i,maxRow);
            cout << "Swapping rows " << i+1 << " and " << maxRow+1 << ":" << endl;
            printMatrix(matrix);
        }

        if (matrix[i][i] == 0)
        {
            cout << "Pivot is zero. Skipping row." << endl;
            continue;
        }

        for (int j = i + 1; j < numRows; ++j)
        {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < numCols; ++k)
            {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }

        cout << "Step " << i + 1 << ":" << endl;
        usleep(1000000);
        printMatrix(matrix);

    }


    vector<double> solution = backSubstitution(matrix);

    cout << "Solution:" << endl;
    char ch = 'a';
    for (int i = 0; i < solution.size(); ++i)
    {

        //cout << "x[" << i << "] = " << solution[i] << endl;
        if(solution[i] >= 0.0)
            cout << char(ch+i) << " = " << " " << solution[i] <<endl;
        else  cout << char(ch+i) << " = " << solution[i] <<endl;
    }

}










