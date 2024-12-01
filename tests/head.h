#ifndef HEAD_H
#define HEAD_H

const int INF = 2000000000;
int pow(int a, int b);
int charToInteger(char* type);
int stringToInteger(char* amount, int size);
int readCharToStringForType(char* input);
int readCharToStringForAmount(char* input);
int stringSize(char* input);
bool isCyrillic(unsigned char firstByte, unsigned char secondByte);
int readCharToStringForInput(char* input);
int defineGender(char* input, int size);
void delete2DMatrix(char** mtrx, int size);
void delete1DMatrix(char* mtrx);

#endif

