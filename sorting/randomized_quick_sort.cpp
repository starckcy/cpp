#include <iostream>
#include <cstdlib>   // for rand()
#include <ctime>     // for time()
using namespace std;

// Function to partition the array (randomized)
int partition(int arr[], int low, int high) {
    // Generate random pivot index
    int randomIndex = low + rand() % (high - low + 1);

    // Swap random pivot with last element
    swap(arr[randomIndex], arr[high]);

    int pivot = arr[high];   // pivot is now random
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Main function
int main() {
    srand(time(0));   // Seed for randomness

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}