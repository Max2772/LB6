#include <iostream>

#include "../header-files/funcs.h"

#include "../../general/header-files/funcs.h"
#include "../../general/header-files/constants.h"

using std::cout;
using std::cin;


void task1(){
    cout << "Программа, для подсчета максимальной группы в строке, состоящей из 0 и 1\n";
    cout << "Введите последовательность из 0 либо 1: ";

    char* input = new char[80];
    while(readCharToStringForInput_Task1(input) == -INF);
    int size = stringSize(input);
    int max_string = maxSubString(input, size);
    printString_Task1(input, size);
    cout << "Самая длинная подгруппа элементов состоит из " << max_string << " чисел\n";

    delete1DMatrix(input);
}