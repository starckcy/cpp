#include <iostream>
#include <climits> // For INT_MIN
#include <algorithm> // For std::max
using namespace std;

void printmax(int arr[], int n, int max) {
    if (n == 0) {
        cout << "Maximum element: " << max << endl;
        return;
    }
    if (arr[n - 1] > max) {
        max = arr[n - 1]; // Update max if the current element is greater
    }
    printmax(arr, n - 1, max); // Recursive call with the remaining elements
}

int maxinarray(int arr[], int n) {
    if (n == 0) return INT_MIN; // Return the smallest integer if the array is empty
    return max(arr[n - 1], maxinarray(arr, n - 1)); 
}

int main() {
    int arr[] = {1, 5, 3, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0]; // Assume the first element is the maximum
    printmax(arr, n, max);
    cout << "Maximum element using maxinarray: " << maxinarray(arr, n) << endl;
    return 0;
}