#pragma once
#include "HeaderFiles.h"
//#include "gnuplot-iostream.h"
#include<bits/stdc++.h>
#include<windows.h>
#include <unistd.h>
#include<math.h>
using namespace std;
void gaussianElimination();
void menu();
void printMatrix( vector<vector<double>>& matrix);
void gaussJordan();
void swapRows(vector<vector<double>>&matrix, int row1, int row2);
vector<double> backSubstitution( vector<vector<double>>& matrix);
void luDecompose(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U, vector<int>& P);
vector<double> solveWithLU( vector<vector<double>>& A, vector<double>& B);
void LU_DECOMPOSITION();
vector<vector<double>> matrixInverse( vector<vector<double>>& A);
vector<vector<double>> matrixMultiply( vector<vector<double>>& A, vector<vector<double>>& B);
double determinant( vector<vector<double>>& A);
void matrixInversion();
vector<double> solveLinearSystem( vector<vector<double>>& A,  vector<double>& B);
void creamerRule();
void jacobiMethod();
