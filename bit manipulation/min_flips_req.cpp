#include<iostream>
using namespace std;

int main(){
    int x = 23;
    int y = 31;

    cout << __builtin_popcount(x ^ y) << endl; // xor of x and y will give the bits which are different, then we can count the number of set bits in the result to get the number of flips required.
    return 0;
}