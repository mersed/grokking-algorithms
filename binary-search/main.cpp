#include <iostream>
#include <vector>

using namespace std;

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

int main(int argc, char** argv) {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {27, 32, 53, 55, 80, 106, 113, 116, 262, 281, 296, 314, 322, 356, 377, 381, 389, 393, 410, 423, 428, 432, 437, 441, 453, 482, 562, 603, 605, 614, 617, 648, 670, 700, 729, 736, 763, 770, 790, 800, 861, 869, 874, 877, 913, 920, 945, 951, 961, 974};

    cout << binarySearch(arr1, 1) << endl;
    cout << "---------------------------" << endl;
    cout << binarySearch(arr2, 377) << endl;
    cout << "---------------------------" << endl;
    cout << binarySearch(arr2, 0) << endl;
    cout << "---------------------------" << endl;
}

