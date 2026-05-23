#include <iostream>
using namespace std;

int countSetBits(int n){
    int count = 0;
    while(n > 0){
        count++;
        n = n & (n-1);
    }
    return count;
}

int main() {
    cout << __builtin_popcount(11) << endl; // 3
    cout << countSetBits(11) << endl; // 3
    return 0;
}