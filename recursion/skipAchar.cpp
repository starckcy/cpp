#include<iostream>
using namespace std;

void removechar(string ans, string str){
    if(str.length() == 0){
        cout<<ans;
        return;
    }

    char ch = str[0];
    if(ch == 'a') removechar(ans, str.substr(1));
    else removechar(ans + ch, str.substr(1));
}

void removechar2(string ans, string str, int idx){
    if(idx == str.length()){
        cout<<ans;
        return;
    }

    char ch = str[idx];
    if(ch == 'a') removechar2(ans, str, idx + 1);
    else removechar2(ans + ch, str, idx + 1);
}

int main(){
    string str = "baccad";
    // string s = "";
    // for(int i=0; i<str.length(); i++){
    //     if(str[i] != 'a'){
    //         s += str[i];
    //     }    }
    // cout<<s;

    removechar("", str);

    return 0;
}