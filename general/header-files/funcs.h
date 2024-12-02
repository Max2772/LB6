#pragma once
#include "constants.h"

int readCharToStringForType(char* input);
int readCharToStringForChoice(char* input);

inline int charToInteger(char* type){  
    return *type - '0';
};

inline int stringSize(char* input){ 
    int i = 0;
    while(input[i] != '\n') ++i;
    return i;
};

inline void delete2DMatrix(char** mtrx, int size){
    for(int i = 0; i < size; ++i)
        delete [] mtrx[i];
        
        delete [] mtrx;
        mtrx = NULL;
};

inline void delete1DMatrix(char* mtrx){
        delete [] mtrx;
        mtrx = NULL;
};

inline int getIntegerForType(){
        char* type = new char[80];
        while(readCharToStringForType(type) == -INF);
        int type_int = charToInteger(type);
        delete1DMatrix(type);
        return type_int;
};

inline int getIntegerForChoice(){
        char* choice = new char[80];
        while(readCharToStringForChoice(choice) == -INF);
        int choice_int = charToInteger(choice);
        delete1DMatrix(choice);
        return choice_int;
};
