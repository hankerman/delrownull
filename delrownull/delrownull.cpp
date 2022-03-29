#include <iostream>
using namespace std;

void createMatr(int**& arr, int row, int cols) {

    arr = new int* [row];

    for (int i = 0; i < row; i++) {
        arr[i] = new int[cols];
    }

}

void fill(int**& arr, int row, int cols) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void print(int**& arr, int row, int cols) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void delMatr(int**& arr, int row) {
    for (int i = 0; i < row; i++) {
        delete[]arr[i];
    }
    delete[]arr;
}

int countNull(int** arr, int row, int cols) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 0) {
                count++;
                break;
            }
        }
    }
    return count;
}

int position(int** arr, int row, int cols) {
    int pos = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 0) {
                pos = i;
                return pos;
            }
        }
        
    }
    return 0;
}

int** delRowNull(int** arr, int& row, int cols) {
    int pos = position(arr, row, cols);
    int** temp = nullptr;
    createMatr(temp, row-1, cols);
    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < pos) {
                temp[i][j] = arr[i][j];
            }
            else {
                temp[i][j] = arr[i + 1][j];
            }
        }
    }
    delMatr(arr, row);
    row--;
    return temp;
}

int main()
{
    
    /*Задание 1. Написать программу, которая удаляет из 
    двухмерного массива, заполненного случайными числами 
    строки, содержащие нулевые элементы.*/

    srand(time(NULL));

    int row, cols, count, pos;

    int** matr = nullptr;

    cout << "Enter row: ";
    cin >> row;
    cout << "Enter cols: ";
    cin >> cols;

    createMatr(matr, row, cols);
    fill(matr, row, cols);
    print(matr, row, cols);

    count = countNull(matr, row, cols);
    cout << count << endl;
    //pos = position(matr, row, cols);
    //cout << pos << endl;

    while (count != 0)
    {
        matr = delRowNull(matr, row, cols);
        count = countNull(matr, row, cols);
    }

    print(matr, row, cols);
    delMatr(matr, row);
}

