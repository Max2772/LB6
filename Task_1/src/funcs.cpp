#include <iostream>

#include "../../general/header-files/constants.h"

using namespace std;

// 11111111111111111111111111111111111111111111111111111111111111111111111111111111
int readCharToStringForInput_Task1(char* input){
    bool invalidInput = false;
    bool tooLongInput = true;
    for(int i = 0; i < 80; ++i){
        input[i] = getchar();
        if(input[i] != '1' && input[i] != '0' && input[i] != '\n'){
            invalidInput = true;
        }
        if(input[i] == '\n'){
            tooLongInput = false;
            break;
        }
    }

    if(tooLongInput){
        cout << "Ввод слишком длинный, введите только 1 или 0: ";
        while((getchar()) != '\n');
        return -INF;
    }

    if(invalidInput){
        cout << "Некорректный ввод, введите только 1 или 0: ";
        return -INF;
    }else if(input[0] == '\n')
        return -INF;

    return 1;
}

int maxSubString(char* input, int size){
    int max_string = 0;
    for(int i = 0; i < size;){
        int cnt = 0;
        if(input[i] == '1'){
            while(input[i] == '1'){++cnt;++i;}
        }else{
                while(input[i] == '0'){++cnt;++i;}
        }

        if(cnt > max_string)
            max_string = cnt;
    
    }
    return max_string;
}

void printString_Task1(char* input, int size){
    cout << "Введенаая строка: ";
    for(int i = 0; i < size; ++i){
        cout << input[i];
    }
    cout << '\n';
}