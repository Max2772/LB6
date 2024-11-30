#include <iostream>

const int INF = 2000000000;

using namespace std;

int charToInteger(char* type){
    return *type - '0';
}

int readCharToStringForType(char* input){
    bool invalidInput = false;
    for(int i = 0; i < 80; ++i){
        input[i] = getchar();
        if(input[i] != '1' && input[i] != '2' && input[i] != '\n'){
            invalidInput = true;
        }
        if(input[i] == '\n') break;
    }
    if(invalidInput){
        cout << "Некорректный ввод, введите только 1 или 2: ";
        return -INF;
    }else if(input[0] == '\n')
        return -INF;

    return 1;
}

int readCharToStringForInput(char* input){
    bool invalidInput = false;
    for(int i = 0; i < 80; ++i){
        input[i] = getchar();
        if(input[i] != '0' && input[i] != '1' && input[i] != '\n'){
            invalidInput = true;
        }
        if(input[i] == '\n') break;
    }
    if(invalidInput){
        cout << "Некорректный ввод, введите только 0 или 1: ";
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

void printString(char* input, int size){
    cout << "Введенаая строка: ";
    for(int i = 0; i < size; ++i){
        cout << input[i];
    }
    cout << '\n';
}

int main(){
    cout << "Программа, для подсчета максимальной группы в строке, состоящей из 0 и 1\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        char* type = new char[80];
        while(readCharToStringForType(type) == -INF);
        int type_int = charToInteger(type);
        if(type_int == 2)
            break;
        else if(type_int != 1 && type_int != 2)
            continue;
        
        cout << "Введите последовательность из 0 либо 1: ";
        char* input = new char[80];
        while(readCharToStringForInput(input) == -INF);
        int size = stringSize(input);
        int max_string = maxSubString(input, size);
        printString(input, size);
        cout << "Самая длинная подгруппа элементов состоит из " << max_string << " чисел\n";
        delete [] input;
        input = NULL;
        delete [] type;
        type = NULL;
    }
    return 0;
}