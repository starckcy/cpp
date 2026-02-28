#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Randomized partition function
int partition(int arr[], int low, int high) {
    // pick random pivot index
    int randomIndex = low + rand() % (high - low + 1);

    // swap random pivot with last element
    swap(arr[randomIndex], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized Quick Select
int randomizedQuickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        // kth smallest element found
        if (pi == k - 1)
            return arr[pi];

        // search left
        else if (pi > k - 1)
            return randomizedQuickSelect(arr, low, pi - 1, k);

        // search right
        else
            return randomizedQuickSelect(arr, pi + 1, high, k);
    }
    return -1;
}

int main() {
    srand(time(0)); // seed for randomness

    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // find 3rd smallest element

    int ans = randomizedQuickSelect(arr, 0, n - 1, k);

    cout << k << "rd smallest element is: " << ans;

    return 0;
}