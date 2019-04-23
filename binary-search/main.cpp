#include <iostream>
#include <vector>

using namespace std;

/**
 * O(logn)
 */
int binarySearch(vector<int> &v, int searchVal) {
    vector<int>::size_type low = 0;
    vector<int>::size_type high = v.size()-1;
    vector<int>::size_type mid;

    while(low <= high) {
        mid = (low + high) / 2;
        if(v[mid] == searchVal) {
            return mid;
        }
        else if(v[mid] > searchVal) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
}

void displayVector(vector<int> &v) {
    cout << "{";
    auto it = v.begin();
    for(; it != v.end()-1; it++) {
        cout << *it << ",";
    }
    cout << *it;
    cout << "}" << endl;
}

void displayInputsAndResult(vector<int> &v, int searchVal) {
    cout << "Searching value " << searchVal << " in array: ";
    displayVector(v);
    cout << "Value position: " << binarySearch(v, searchVal) << endl;
    cout << "---------------------------" << endl;
}

int main(int argc, char** argv) {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {27, 32, 53, 55, 80, 106, 113, 116, 262, 281, 296, 314, 322, 356, 377, 381, 389, 393, 410, 423, 428, 432, 437, 441, 453, 482, 562, 603, 605, 614, 617, 648, 670, 700, 729, 736, 763, 770, 790, 800, 861, 869, 874, 877, 913, 920, 945, 951, 961, 974};
    vector<int> arr3 = {1, 2, 6, 7, 9, 14, 15, 16, 17, 21, 26, 28, 32, 34, 49};

    displayInputsAndResult(arr1, 1);
    displayInputsAndResult(arr1, 2);
    displayInputsAndResult(arr1, 0);
    displayInputsAndResult(arr1, 5);
    displayInputsAndResult(arr2, 377);
    displayInputsAndResult(arr3, 49);
}

