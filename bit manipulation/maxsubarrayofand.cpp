#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[] = {12, 3, 5, 8, 6, 7, 13, 13, 13, 2, 8, 18, 75, 6, 7, 12, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxele = INT_MIN;
    int ans = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > maxele) {
            maxele = arr[i];
            count = 1;
        }
        else if(arr[i] == maxele) {
            count++;
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
    return 0;
}