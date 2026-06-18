#include<iostream>
using namespace std;

void findUnique(int arr[], int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }

    int temp=ans;
    int k=0;
    while(true) {
        if((temp & 1) == 1){
            break;
        }
        k++;
        temp = temp >> 1;
    }

    int retval = 0;
    for(int i = 0; i < n; i++) {
        if(((arr[i] >> k) & 1) == 1){
            retval = retval ^ arr[i];
        }
    }
    cout << retval << " " << (ans ^ retval) << endl;

}

int main(){
    int arr[] = {1, 2, 3, 7, 1, 2, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    findUnique(arr, n);
    return 0;
}