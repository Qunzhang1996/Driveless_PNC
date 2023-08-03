#include <iostream>
using namespace std;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble_Sort(int Array[], int n) {
    bool swapped;
    for (int k = 1; k < n; k++) {
        swapped = false;
        for (int i = 0; i < n - k; i++) {
            if (Array[i] > Array[i + 1]) {
                Swap(&Array[i], &Array[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            // No swaps in this iteration, array is already sorted
            break;
        }
    }
}

int main() {
    int Array_[] = {2, 4, 1, 5, 3, 7};
    int n = sizeof(Array_) / sizeof(Array_[0]);
    Bubble_Sort(Array_, n);
    for (int i = 0; i < n; i++) {
        cout << Array_[i] << endl;
    }
    return 0;
}
