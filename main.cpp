#include <iostream>
#include "tests/head.h"
#include "tests/funcs.cpp"

using namespace std;


int main(){
    cout << "Программа, для подсчета слов мужского, женского и среднего рода(Русский язык)\n";
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
        
        cout << "Введите количество слов(натуральное число): ";
        char* amount = new char[80];
        while(readCharToStringForAmount(amount) == -INF);
        int amount_size = stringSize(amount);
        int amount_int = stringToInteger(amount, amount_size);

        char** input = new char*[amount_int];
        for(int i = 0; i < amount_int; ++i)
            input[i] = new char[160];

        for(int i = 0; i < amount_int; ++i){
            cout << "Введите " << i+1 << " слово: ";
            while(readCharToStringForInput(input[i]) == -INF);
        }

        cout << "Введенные слова: ";
        for(int i = 0; i < amount_int; ++i){
            for(int j = 0; input[i][j] != '\n'; ++j){
                cout << input[i][j];
            }
            cout << ' ';
        }
        cout << '\n';

        int male = 0, woman = 0, neutral = 0;

        for(int i = 0; i < amount_int; ++i){
            int size = stringSize(input[i]);
            int cnt = defineGender(input[i], size);
            cnt == 0 ? ++male : cnt == 1 ? ++woman : ++neutral;
        }        

        cout << "Слов мужского рода: " << male << '\n';
        cout << "Слов женского рода: " << woman << '\n';
        cout << "Слов среднего рода: " << neutral << '\n';

        delete2DMatrix(input, amount_int);
        delete1DMatrix(type);
        delete1DMatrix(amount);
    }
    return 0;
}