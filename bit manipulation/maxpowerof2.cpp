#include <iostream>
using namespace std;

int maxpowerof2(int n){
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);
    return n - (n >> 1); // or we can use (n+1) >> 1
}

int main() {
    int n = 23;
    int temp;
    while(n){
        temp = n;
        n = n & (n-1);
    }
    cout << temp << endl; // 16
    cout<<maxpowerof2(23)<<endl; // 16
    return 0;
}