#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    long long x;
    cin >> x;
    int down, up;
    up = 1;
    down = 1;
    if (x == 0) {
        cout << 0 << endl;
    }
    while ((x & 1) == 0) x = x >> 1;
    x = x >> 1;
    while (x != 0) {
        if ((x & 1) == 1) {
            up = min(up, down) + 1;
        } else {
            down = min(up, down) + 1;
        }
        x = x >> 1;
    }
    cout << up << endl;
    return 0;
}
