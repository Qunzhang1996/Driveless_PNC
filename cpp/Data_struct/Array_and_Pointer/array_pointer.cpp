#include <iostream>

void printIntArray(int *arr[], int size[], int numArrays) {
    for (int i = 0; i < numArrays; i++) {
        std::cout << "A[" << i << "] = ";
        for (int j = 0; j < size[i]; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int size0 = 3, size1 = 5, size2 = 2;

    int* A[8];
    A[0] = new int[size0]{1, 2, 3};
    A[1] = new int[size1]{10, 20, 30, 40, 50};
    A[2] = new int[size2]{100, 200};

    // Initialize other elements to null pointers to indicate they are not used
    for (int i = 3; i < 8; i++) {
        A[i] = nullptr;
    }

    int sizes[3] = {size0, size1, size2};

    std::cout << "Array of Pointers to Dynamically Allocated Arrays of Integers:\n";
    printIntArray(A, sizes, 3);

    // Don't forget to deallocate the dynamically allocated memory
    for (int i = 0; i < 8; i++) {
        if (A[i] != nullptr) {
            delete[] A[i];
        }
    }

    return 0;
}
