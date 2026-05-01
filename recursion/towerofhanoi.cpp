#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c){
    if(n == 0) return;
    hanoi(n - 1, a, c, b); // Move n-1 disks from A to C using B as auxiliary
    cout << a << " -> " << c << endl; // Move the nth disk from A to C
    hanoi(n - 1, b, a, c); // Move n-1 disks from B to C using A as auxiliary
}

int main() {
    int n = 3; // Number of disks
    hanoi(n, 'A', 'B', 'C'); // A, B and C are names of rods
    return 0;
}