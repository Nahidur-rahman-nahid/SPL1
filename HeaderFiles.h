#pragma once
#include "HeaderFiles.h"
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

