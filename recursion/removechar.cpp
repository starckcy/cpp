#include <iostream>
using namespace std;

void removechar(string str, string newstr, char ch, int i) {
    if(i == str.length()) {
        cout << newstr << endl;
        return;
    }
    char c = str[i];
    if(c == ch) removechar(str, newstr, ch, i + 1);
    else removechar(str, newstr + c, ch, i + 1);

}

int main() {
    string str = "hello world";
    char ch = 'l';
    removechar(str, "", ch, 0);
    return 0;
}