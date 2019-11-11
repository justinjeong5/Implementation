/*
 * 2019.1.7
 * Selection_Sort
 */
#include <iostream>

using namespace std;

void selectionSort(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void show(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N, input;
    cin >> N;

    int *arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> input;
        arr[i] = input;
    }

    selectionSort(arr, N);

    show(arr, N);

    system("pause");
    return 0;
}


// 10 5 9 6 7 3 4 1 10 2 8