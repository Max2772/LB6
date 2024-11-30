#include <iostream>
#include "tests/head.h"
#include "tests/funcs.cpp"

using namespace std;


int main(){
    cout << "Программа, для замены каждой буквы её номером в алфавите(Для латиницы)\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        char* type = new char[80];
        while(readCharToStringForType(type) == -INF);
        int type_int = charToInteger(type);
        if(type_int == 2){
            delete [] type;
            break;
        }
        else if(type_int != 1 && type_int != 2){
            delete [] type;
            continue;
        }
        
        cout << "Введите текст: ";

        char* input = new char[80];
        while(readCharToStringForInput(input) == -INF);
        int size = stringSize(input);
        printString(input, size);
        
        delete [] type;
        type = NULL;
        delete [] input;
        input = NULL;
    }
    return 0;
}