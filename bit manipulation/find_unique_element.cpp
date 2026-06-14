#include <iostream>
using namespace std;

// x ^ x = 0
// x ^ 0 = x

int main() {
    int arr[] = {1, 2, 3, 7, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans=0;
    for(int i = 0; i < n; i++) {
        ans = ans ^ arr[i]; // xor of all the elements will give us the unique element as the duplicate elements will cancel each other out.
    }
    cout << ans << endl;
    return 0;
}