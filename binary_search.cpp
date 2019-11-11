/*
 * binary_search
 */

#include <iostream>

using namespace std;

#define MAX_SIZE 1024

int binary_array[MAX_SIZE];

int BSearch(int arr[], int target) {
    int low = 0;
    int high = arr->length() - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int N, temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
    }


}

//10		4 2 9 1 7 3 6 5 8 10