#include <iostream>
#include <vector>
using namespace std;

void printsubset(int arr[], int n, int idx, vector<int> v, int k){
    if(idx == n){
        if(v.size() == k){
            for(int ele : v){
                cout << ele << " ";
            }
            cout << endl;
        }
        return;
    }
    printsubset(arr, n, idx + 1, v, k);
    v.push_back(arr[idx]);
    printsubset(arr, n, idx + 1, v, k);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    int k = 3;
    printsubset(arr, n, 0, v, 3);
    return 0;
}