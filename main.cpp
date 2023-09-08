#include "HeaderFiles.h"
//#include <bits/stdc++.h>
//#include <windows.h>
using namespace std;
void menu();

int main(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD buffersize = {80,50};
    SetConsoleScreenBufferSize(hConsole,buffersize);
    // Change text color to green
    CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(info);
    GetConsoleScreenBufferInfoEx(hConsole,&info);
    info.ColorTable[6] = RGB(255,255,0);//RGB values for yellow
    info.wAttributes = (info.wAttributes & 0xFFF0)| BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN;
    SetConsoleScreenBufferInfoEx(hConsole,&info);

    menu();

    for(int i = 0;i < buffersize.Y;i++){
       for(int j = 0;j < buffersize.X;++j){
           cout << " ";
       }
    }

    return 0;
}



