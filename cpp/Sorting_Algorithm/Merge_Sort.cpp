#include <iostream>
#include <vector>

// Function to merge two sorted sub-arrays into a single sorted array
void merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right) {
    int i = 0; // Initial index of the left sub-array
    int j = 0; // Initial index of the right sub-array
    int k = 0; // Initial index of the merged array

    // Merge the temporary arrays back into the main array
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            ++i;
        } else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of leftArray, if any
    while (i < left.size()) {
        arr[k] = left[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of rightArray, if any
    while (j < right.size()) {
        arr[k] = right[j];
        ++j;
        ++k;
    }
}

// Merge Sort function
void mergeSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return;

    int mid = n / 2;
    std::vector<int> left;
    std::vector<int> right;

    // Populate the left and right arrays
    for (int i = 0; i < mid; i++) {
        left.push_back(arr[i]);
    }
    for (int i = mid; i < n; i++) {
        right.push_back(arr[i]);
    }

    // Recursively sort the left and right halves
    mergeSort(left);
    mergeSort(right);

    // Merge the sorted left and right halves
    merge(arr, left, right);
}

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    mergeSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
