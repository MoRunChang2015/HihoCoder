#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int getMonthNumber(string str) {
    if (str == "January") return 1;
    if (str == "February") return 2;
    if (str == "March") return 3;
    if (str == "April") return 4;
    if (str == "May") return 5;
    if (str == "June") return 6;
    if (str == "July") return 7;
    if (str == "August") return 8;
    if (str == "September") return 9;
    if (str == "October") return 10;
    if (str == "November") return 11;
    if (str == "December") return 12;
}
int main() {
    //ios::sync_with_stdio(false);
    int ans, l, r, m, d, t, temp, i;
    string month;
    i = 0;
    cin >> t;
    while (t--) {
        i++;
        cin >> month >> d;
        getchar();
        cin >> temp;
        m = getMonthNumber(month);
        if (m <= 2)
            l = temp - 1;
        else
            l = temp;
        getchar();
        cin >> month >> d;
        getchar();
        cin >> temp;
        getchar();
        m = getMonthNumber(month);
        if (m == 2 && d == 29 || m > 2)
            r = temp;
        else
            r = temp - 1;
        ans = r / 4 - r / 100 + r / 400;
        ans -= (l / 4 - l / 100 + l / 400);
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
