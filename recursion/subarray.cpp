#include <iostream>
#include <vector>
using namespace std;

// this function will work only when array has unique elements, if there are duplicate elements in the array, then we need to use a set to store the subarrays and check for duplicates before printing the subarray.

void subarray(vector<int> v, int arr[], int n, int i) {
    if (i == n) {
        for (int i=0; i<v.size(); i++) {
            cout << v[i];
        }
        cout << endl;
        return;
    }
    subarray(v, arr, n, i + 1);  // not including the current element
    if(v.size() == 0 || arr[i-1] < v[v.size() - 1]){  // if the i-1 th element is less than the last element in the vector, then we can include the current element or if the vector is empty, we can include the current element
        v.push_back(arr[i]);  // including the current element
        subarray(v, arr, n, i + 1);
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // for(int i = 0; i < n; i++){  // starting point of subarray
    //     for(int j = i; j < n; j++){  // ending point of subarray
    //         for(int k = i; k <= j; k++){  // printing the subarray from index i to j
    //             cout << arr[k] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    vector<int> v;
    subarray(v, arr, n, 0);
    return 0;
}