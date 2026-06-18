#include<iostream>
#include<cmath>
using namespace std;

int printfactors(int n){
    for(int i = 1; i < sqrt(n); i++){
        if(n % i == 0){
            cout << i << " ";
        }
    }
    
    for(int i = sqrt(n); i >= 1; i--){
        if(n % i == 0){
            cout << n/i << " ";
        }
    }
    cout << endl;
    return 0;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printfactors(n);
    return 0;
}