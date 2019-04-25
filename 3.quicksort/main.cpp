#include <iostream>
#include <vector>

using namespace std;


/**
 * This function takes last element as pivot, places 
 * the pivot element at its correct position in sorted 
 * array, and places all smaller (smaller than pivot) 
 * to left of pivot and all greater elements to right 
 * of pivot
 */
int partition(int* arr, int low, int high) {
    int pivot = arr[(low + high)/2];

    while(low <= high) {
        while(arr[low] < pivot) {
            low++;
        }

        while(arr[high] > pivot) {
            high--;
        }

        if(low <= high) {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }

    return low;
}

/**
 * O(nlogn)
 */
void quickSort(int* arr, int low, int high) {
    if(low >= high) {
        return;
    }

    int index = partition(arr, low, high);
    quickSort(arr, low, index - 1);
    quickSort(arr, index, high);
}

void printArray(int arr[], int size)  {
    cout << "{";
    for (int i=0; i < size - 1; i++) {
        cout << arr[i] << ","; 
    }
    cout << arr[size - 1];
    cout << "}" << endl;
}

void displayInputsAndResult(int* arr, int n) {
    cout << "Input arr : ";
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Sorted arr: ";
    printArray(arr, n);
    cout << "----------------------------------" << endl;
}

int main(int argc, char** argv) {
    int arr1[] = {193, 53, 185, 49, 113, 176, 66, 100, 133, 63};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    displayInputsAndResult(arr1, n1);

    int arr2[] = {121, 63, 110, 101, 80, 163, 61, 103, 128, 167};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    displayInputsAndResult(arr2, n2);

    int arr3[] = {159, 120, 17, 195, 8, 92, 192, 4, 178, 113};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    displayInputsAndResult(arr3, n3);
}

