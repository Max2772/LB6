#include <iostream>

#include "../header-files/funcs.h"

#include "../../general/header-files/funcs.h"
#include "../../general/header-files/constants.h"

using std::cout;
using std::cin;


void task2(){
    cout << "Программа, для замены каждой буквы её номером в алфавите(Для латиницы)\n";       
    cout << "Введите текст: ";

    char* input = new char[80];
    while(readCharToStringForInput_Task2(input) == -INF);
    int size = stringSize(input);
    printString_Task2(input, size);
    
    delete1DMatrix(input);
}