#include<bits/stdc++.h>
#include<windows.h>
#include <unistd.h>
using namespace std;

// void printMatrix(const vector<vector<double>>& matrix) {
//     for (const auto& row : matrix) {
//         for (double val : row) {
//                 if(val >= 0)cout << " " << val << "   ";
//                 else
//                 cout << fixed << setprecision(2) <<  val << "   " << setw(8);
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

void printMatrix(const vector<vector<double>>& matrix)
{
    int numCols = matrix[0].size();
    vector<int> colWidths(numCols, 0);

    // Calculate maximum width needed for each column
    for (const auto& row : matrix)
    {
        for (int i = 0; i < numCols; ++i)
        {
            int width = to_string(int(row[i])).length() + 3; // Including sign and decimal points
            colWidths[i] = max(colWidths[i], width);
        }
    }

    for (const auto& row : matrix)
    {
        for (int i = 0; i < numCols; ++i)
        {
            cout << fixed << setprecision(2) << setw(colWidths[i]);
            if(i != 0)
            {
                cout << " "; // Add a space before positive values (excluding the first column)
            }
            cout << row[i];
        }
        cout << endl;
    }
    cout << endl;
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

vector<double> backSubstitution(const vector<vector<double>>& matrix)
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
    cout << "enter the number of equations: ";

    //freopen("linearSystemEquations.txt","r",stdin);
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
        cout << char(ch+i) << " = " << solution[i] <<endl;
    }

}
void menu(){
    cout <<  "\t\t\t\t\t\t***********************************\n";
    cout <<  "\t\t\t\t\t\t  Linear System Equations Solver   \n";
    cout <<  "\t\t\t\t\t\t***********************************\n\n\n";

    cout <<  "\t\t\t\tMETHODS:\n";
    cout <<  "\t\t\t\t--------\n";
    cout<<"\t\t\t\t\t\t 1. Gaussian Elimination\n\n";
    cout<<"\t\t\t\t\t\t 2. Gauss-Jordan Elimination\n\n";
    cout<<"\t\t\t\t\t\t 3. LU Decomposition\n\n";
    cout<<"\t\t\t\t\t\t 4. Matrix Inversion \n\n";
    cout<<"\t\t\t\t\t\t 5. Creamer's Rule\n\n";
    cout<<"\t\t\t\t\t\t 6. Exit \n\n\n";
    cout << "Select your preferred method to solve the system : ";
    int choice;
    cin >> choice;
    switch(choice){
      case 1:gaussianElimination();
             break;

      case 6:exit(0);
      break;
      default :cout << "invalid choice" << endl,menu();


    }
}







