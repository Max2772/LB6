#include <iostream>

#include "../header-files/funcs.h"

#include "../../general/header-files/funcs.h"
#include "../../general/header-files/constants.h"

using namespace std;


void task3(){
    cout << "Программа, для подсчета слов мужского, женского и среднего рода(Русский язык)\n";      
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
    delete1DMatrix(amount);
}