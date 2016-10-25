#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int i, j;
    char c;
    string str, origin;
    while (cin >> str) {
        c = getchar();
        origin = str;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if (str.find("marshtomp") != string::npos) {
            int t = str.find("marshtomp");
            cout << origin.replace(t, 9, "fjxmlhx");
        } else
            cout << origin;
        cout << c;
    }
}
