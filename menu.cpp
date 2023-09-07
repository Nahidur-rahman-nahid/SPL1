#include "HeaderFiles.h"
void menu(){
    cout <<  "\t\t\t\t\t\t***********************************\n";
    cout <<  "\t\t\t\t\t\t  Linear System Equations Solver   \n";
    cout <<  "\t\t\t\t\t\t***********************************\n\n\n";

    cout <<  "\t\t\t\tMETHODS:\n";
    cout <<  "\t\t\t\t--------\n";
    cout <<"\t\t\t\t\t\t 1. Gaussian Elimination\n\n";
    cout <<"\t\t\t\t\t\t 2. Gauss-Jordan Elimination\n\n";
    cout <<"\t\t\t\t\t\t 3. LU Decomposition\n\n";
    cout <<"\t\t\t\t\t\t 4. Matrix Inversion \n\n";
    cout <<"\t\t\t\t\t\t 5. Creamer's Rule\n\n";
    cout <<"\t\t\t\t\t\t 6. Exit \n\n\n";
    cout << "Select your preferred method to solve the system : ";
    int choice;
    cin >> choice;
    switch(choice){
      case 1:gaussianElimination();
             break;
      case 2:gaussJordan();
             break;
      case 3:
      case 4:
      case 5:
      case 6:exit(0);
             break;
      default :cout << "invalid choice" << endl,menu();


    }
}


