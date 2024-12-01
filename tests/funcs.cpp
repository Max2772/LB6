#include <iostream>
#include "head.h"

using namespace std;

int pow(int a, int b){
    if(b == 0)
        return 1;

    int res = a;
    for(int i = 1; i < b; ++i) res *= a;
    return res;
}

int charToInteger(char* type){
    return *type - '0';
}

int stringToInteger(char* amount, int size){
    int res = 0;
    for(int i = 0; i < size; ++i){
        res += (amount[i] - '0') * pow(10, size - i - 1);
    }
    return res;
}

int readCharToStringForType(char* input){
    bool invalidInput = false;
    bool tooLongInput = true;
    for(int i = 0; i < 80; ++i){
        input[i] = getchar();
        if(input[i] != '1' && input[i] != '2' && input[i] != '\n'){
            invalidInput = true;
        }
        if(input[i] == '\n'){
            tooLongInput = false;
            break;
        }
    }

    if(tooLongInput){
        cout << "Ввод слишком длинный, введите только 1 или 2: ";
        while((getchar()) != '\n');
        return -INF;
    }

    if(invalidInput || (input[1] != '\n')){
        cout << "Некорректный ввод, введите только 1 или 2: ";
        return -INF;
    }else if(input[0] == '\n')
        return -INF;

    return 1;
}

int readCharToStringForAmount(char* input){
    bool invalidInput = false;
    bool tooLongInput = true;
    for(int i = 0; i < 80; ++i){
        input[i] = getchar();
        if(((input[i] < 48) || (input[i] > 57)) && input[i] != '\n'){
            invalidInput = true;
        }
        if(input[i] == '\n'){
            tooLongInput = false;
            break;
        }
    }

    if(tooLongInput){
        cout << "Ввод слишком длинный, введите натурально число(без пробелов): ";
        while((getchar()) != '\n');
        return -INF;
    }

    if(invalidInput || (input[0] == '0')){
        cout << "Некорректный ввод, введите натурально число(без пробелов): ";
        return -INF;
    }else if(input[0] == '\n')
        return -INF;

    return 1;
}

int stringSize(char* input){
    int i = 0;
    while(input[i] != '\n') ++i;
    return i;
}

bool isCyrillic(unsigned char firstByte, unsigned char secondByte) {
    return 
        ((firstByte == 0xD0 && secondByte >= 0x90 && secondByte <= 0xBF) || 
        (firstByte == 0xD1 && secondByte >= 0x80 && secondByte <= 0x8F)) || 
        (firstByte == 0xD0 && secondByte == 0x81) ||
        (firstByte == 0xD1 && secondByte == 0x91);
}


int readCharToStringForInput(char* input){
    bool invalidInput = false;
    bool tooLongInput = true;
    int j = 0;
    while(j < 160){
        unsigned char current = getchar();

        if(current == '\n'){
            tooLongInput = false;
            input[j] = current;
            break;
        }

        if((current & 0xC0) == 0xC0){
            unsigned char next = getchar();
            if(isCyrillic(current, next)){
                input[j] = current;
                input[j+1] = next; 
                j += 2;
            } else {
                invalidInput = true;
            }
        }else if(current < 0x80){
            invalidInput = true;
            ++j;
        }else{
            invalidInput = true;
            ++j;
        }
    }


    if(tooLongInput){
        cout << "Ввод слишком длинный, введите текст до 80 символов: ";
        while((getchar()) != '\n');
        return -INF;
    }

    if(invalidInput){
        cout << "Некорректный ввод, введите только текст на кириллице: ";
        return -INF;
    }else if(input[0] == '\n')
        return -INF;

    return 1;
}


int defineGender(char* input, int size){
    unsigned char secondLastChar = input[size-2];
    unsigned char lastChar = input[size-1];
    unsigned int utf8Char = (secondLastChar << 8) | lastChar;
    if(utf8Char == 0xD0B0 || utf8Char == 0xD18F || utf8Char == 0xD090 || utf8Char == 0xD0AF){
        return 1;
    }else if (utf8Char == 0xD0BE || utf8Char == 0xD0B5 || utf8Char == 0xD09E || utf8Char == 0xD095){
        return 2;
    }else
        return 0; 
}
