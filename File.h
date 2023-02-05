# pragma once
# include <iostream>

using namespace std;

void RandomFillArray (int* arr, int size, int start, int end){
    srand (time (0));
    for (int i = 0; i < size; ++i){
        arr[i] = start + rand ()% (end - start + 1);
    }
}

void PrintArray(int* arr, int size)
{
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}