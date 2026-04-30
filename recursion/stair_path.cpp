#include <iostream>
using namespace std;

int stair(int n){
    if(n == 0) return 1;
    if(n < 0) return 0;
    return stair(n-1) + stair(n-2);
}

int stair_three(int n){
    if(n == 0) return 1;
    if(n < 0) return 0;
    return stair_three(n-1) + stair_three(n-2) + stair_three(n-3);
}

int main() {
    cout<<stair(5)<<endl;
    cout<<stair_three(5)<<endl;
    return 0;
}