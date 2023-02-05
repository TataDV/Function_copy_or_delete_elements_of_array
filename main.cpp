/* Щигарцова Татьяна Группа БВ215
 *
 * 1. Написать функцию по удалению
 * из массива группы элементов. Значения индексов
 * диапазона удаляемых элементов задаются пользователем.
 * Удаляемые элементы должны распологаться рядом, без разрывов*/
#include <iostream>
#include "File.h"
using namespace std;

int CalcAmountElementsForDeleteIndexes (int* arr, int size, int index_1, int index_2) {
    int count = 0;
    for (int i = 0; i < (size -(index_2 - index_1) - 1 ); ++i) {
            count++;
    } return count;
}

int* DeleteElementsFromArrayOnIndexes(int* arr, int size, int index_1, int index_2, int &new_size){
    int count = CalcAmountElementsForDeleteIndexes (arr, size, index_1, index_2);
    new_size = count;
    int* temp = new int [new_size];

    for (int i = 0, j = 0; i < size; ++i){
        if (i >= index_1 && i <= index_2) continue;
        temp[j] = arr [i];
        j++;
    }

    return temp;
}

/*2. Написать функцию по копированию
 * из массива группы элементов. Значения индексов
 * диапазона копируемых элементов задаются пользователем.
 * Копируемые элементы должны распологаться рядом, без разрывов*/

int CalcAmountElementsForCopyIndexes (int* arr, int size, int index_1, int index_2) {
    int count_2 = 0;
    count_2 = index_2 - index_1 + 1;

    return count_2;
}

int* CopyElementsFromArrayOnIndexes(int* arr, int size, int index_1, int index_2, int &new_size){
    int count_3 = CalcAmountElementsForCopyIndexes (arr, size, index_1, index_2);
    new_size = count_3;
    int* temp = new int [new_size];

    for (int i = 0, j = 0; i < size; ++i){
        if (i >= index_1 && i <= index_2){
            temp[j] = arr [i];
            j++;
        }
    }
    return temp;
}

int main() {
    int size = 12;
    int source[size];

    RandomFillArray(source, size, -10, 10);
    PrintArray(source, size);

    int index_1, index_2;
    cout << "Enter the first and last index of the array to cut out a range of numbers"<< endl;
    cin >> index_1;
    cin >> index_2;

    int count_of_new_indexes = CalcAmountElementsForDeleteIndexes(source,size,index_1,index_2);
    cout << "count_of_new_indexes  " << count_of_new_indexes << endl;

    int size2;
    int* arr = DeleteElementsFromArrayOnIndexes(source,size,index_1,index_2,size2);
    PrintArray(arr,size2);

    int count_of_new_indexes_2 = CalcAmountElementsForCopyIndexes (source,size,index_1,index_2);
    cout << "count_of_new_indexes_2  " << count_of_new_indexes_2 << endl;

    int size3;
    int* arr_2 = CopyElementsFromArrayOnIndexes (source, size, index_1,index_2,size3);
    PrintArray(arr_2,size3);

    delete[] arr;
    delete arr_2;


    return 0;
}
