/*
 *	2019.1.7
 *	insertion_sort
 */
#include <iostream>

using namespace std;

void insertionSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j >= 0; j--) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
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

    insertionSort(arr, N);
    show(arr, N);

    system("pause");
    return 0;
}

// 10  5 6 3 8 4 9 7 2 1 10
