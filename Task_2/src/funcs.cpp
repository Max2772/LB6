#include <iostream>

#include "../../general/header-files/constants.h"


using namespace std;

int readCharToStringForInput_Task2(char* input){
    bool invalidInput = false;
    bool tooLongInput = true;
    for(int i = 0; i < 80; ++i){
        input[i] = getchar();
        if(((input[i] != 32 && input[i] < 64) || (input[i] > 90 && input[i] < 97) || (input[i] > 122)) && input[i] != '\n'){
            invalidInput = true;
        }
        if(input[i] == '\n'){
            tooLongInput = false;
            break;
        }
    }

    if(tooLongInput){
        cout << "Ввод слишком длинный, введите текст до 80 символов: ";
        while((getchar()) != '\n');
        return -INF;
    }

    if(invalidInput){
        cout << "Некорректный ввод, введите только текст на латинице: ";
        return -INF;
    }else if(input[0] == '\n')
        return -INF;

    return 1;
}

int getAlphabetNumber(char input){
    if(input < 91){
        return (int)input - 64;
    }else{
        return (int)input - 96;
    }
}


void printString_Task2(char* input, int size){
    cout << "Полученный перевод: ";
    for(int i = 0; input[i] != '\n'; ++i){
        if(input[i] == ' ')
            cout << ' ';
        else{
            if((input[i+1] == ' ' && i+1 < size) || i == size - 1)
                cout << getAlphabetNumber(input[i]) << " ";
            else
                cout << getAlphabetNumber(input[i]) << ", ";
        }

    }
    cout << '\n';
}