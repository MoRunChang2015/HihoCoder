#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int a[11] = {0};
int d[5] = {0};
int main() {
    for (int i = 1; i <= 4; i++) {
        cin >> d[i];
        a[d[i]]++;
    }
    int h = 23, m = 59;
    while (h >= 0) {
        bool flag = true;
        if (a[h / 10] != 0) {
            a[h / 10]--;
        } else {
            flag = false;
        }
        if (flag && a[h % 10] != 0) {
            a[h % 10]--;
        } else {
            flag = false;
        }
        if (flag && a[m / 10] != 0) {
            a[m / 10]--;
        } else {
            flag = false;
        }
        if (flag && a[m % 10] != 0) {
            a[m % 10]--;
        } else {
            flag = false;
        }
        if (flag) {
            if (h < 10) cout << "0";
            cout << h << ":";
            if (m < 10) cout << "0";
            cout << m << endl;
            return 0;
        }
        memset(a, 0, sizeof a);
        for (int i = 1; i <= 4; i++) a[d[i]]++;
        m--;
        if (m == -1) {
            h--;
            m = 59;
        }
    }
    cout << "NOT POSSIBLE" << endl;
    return 0;
}
