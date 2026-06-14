#include <iostream>
using namespace std;

int flip_bits(int n) {
    int temp = n;
    int mask = 0;

    while (temp) {
        mask = (mask << 1) | 1;
        temp >>= 1;
    }

    return n ^ mask;
}

int flip_bits2(int n) {
    int x = n;
    int temp;
    while(n){
        temp = n;
        n = n & (n-1);
    }
    return x ^ ((temp * 2) - 1); // or (temp << 1) - 1;
}

int main() {
    int n = 23;   // 10111
    cout << flip_bits(n) << endl;
    cout << flip_bits2(n) << endl;
    return 0;
}