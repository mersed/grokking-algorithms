#include <iostream>
#include <vector>

using namespace std;

/**
 * O(n^2)
 * This example use simplified version of creating temp vector,
 * and removing data from one vector to another sorted vector
 */
void selectionSort(vector<int> &v) {
    vector<int> temp = {};

    while(!v.empty()) {
        int min = v[0];
        auto minIt = v.begin();

        auto it = v.begin();
        while(it != v.end()) {
            if(*it <= min) {
                min = *it;
                minIt = it;
            }
            
            it++;
        }
        
        minIt = v.erase(minIt);
        temp.push_back(min);
    }

    v = temp;
}

void printVector(vector<int> &v) {
    cout << "{";
    auto it = v.begin();
    for(; it != v.end()-1; it++) {
        cout << *it << ",";
    }
    cout << *it;
    cout << "}" << endl;
}

void displayInputsAndResult(vector<int> &v) {
    cout << "Sorting array: ";
    printVector(v);
    selectionSort(v);
    cout << "Sorted array : ";
    printVector(v);
    cout << "------------------------------------------------------------" << endl;
}



/**
 * O(n^2)
 * This example use arrays and swaping without creation of temp array.
 */
void selectionSortWithSwap(int* arr, int size) {
    for(int i=0; i < size-1; i++) {
        int min = i;

        for(int j=i+1; j < size; j++ ) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        
        swap(arr[i], arr[min]);
    }
}

void printArray(int arr[], int size)  {
    cout << "{";
    for (int i=0; i < size - 1; i++) {
        cout << arr[i] << ","; 
    }
    cout << arr[size - 1];
    cout << "}" << endl;
} 

int main(int argc, char** argv) {
    // Using simplified version with vectors
    vector<int> v1 = {121, 63, 110, 101, 80, 163, 61, 103, 128, 167};
    vector<int> v2 = {193, 53, 185, 49, 113, 176, 66, 100, 133, 63};
    vector<int> v3 = {159, 120, 17, 195, 8, 92, 192, 4, 178, 113};
    vector<int> v4 = {196, 199, 11, 73, 157, 113, 89, 97, 130, 162};
    vector<int> v5 = {37, 71, 188, 132, 59, 5, 150, 136, 3, 146};

    displayInputsAndResult(v1);
    displayInputsAndResult(v2);
    displayInputsAndResult(v3);
    displayInputsAndResult(v4);
    displayInputsAndResult(v5);

    // Using version with arrays
    int n = 10;
    int arr1[n] = {121, 63, 110, 101, 80, 163, 61, 103, 128, 167};
    cout << "Sorting array: ";
    printArray(arr1, n);
    selectionSortWithSwap(arr1, n);
    cout << "Sorted array : ";
    printArray(arr1, n);

}

