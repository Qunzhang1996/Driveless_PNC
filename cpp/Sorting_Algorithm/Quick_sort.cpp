#include <iostream>
#include <vector>

// Function to partition the array
int partition(std::vector<int>& arr, int low, int high) 
{
    int pivot = arr[high];
    int PIndex = low;
    for(int i=low;i<high;i++)
    {
        if(arr[i]<=pivot)
        {
            std::swap(arr[i],arr[PIndex]);
            PIndex++;
        }
    }
    std::swap(arr[high],arr[PIndex]);
    return PIndex;
}

// Recursive function for QuickSort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        // Recursive calls for the two subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    std::cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
