#include <iostream>
using namespace std;

int mazepath(int sr, int sc, int er, int ec){
    if(sr == er && sc == ec) return 1;
    if(sr > er || sc > ec) return 0;
    return mazepath(sr+1, sc, er, ec) + mazepath(sr, sc+1, er, ec);
}

int mazepath2(int row, int col){
    if(row <= 0 || col <= 0) return 0;
    if(row == 1 || col == 1) return 1;
    return mazepath2(row-1, col) + mazepath2(row, col-1);
}

void printmazepath(int sr, int sc, int er, int ec, string s){
    if(sr == er && sc == ec) {
        cout<<s<<endl;
        return;
    }
    if(sr > er || sc > ec) return;
    printmazepath(sr+1, sc, er, ec, s+"R"); // R for right
    printmazepath(sr, sc+1, er, ec, s+"D"); // D for down
}

int main() {
    cout<<mazepath(1,1,5,5)<<endl;
    cout<<mazepath2(3,4)<<endl;
    printmazepath(1,1,3,3,"");
    return 0;
}