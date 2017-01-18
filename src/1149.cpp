#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string str;
int f[1020][1020];
const int MOD = 100007;
int main() {
    int t, len;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cin >> str;
        len = str.length();
        int i, j;
        for (i = 0; i < len; i++)
            for (j = 0; j < len; j++) f[i][j] = 0;
        for (i = 0; i < len; i++) f[i][1] = 1;
        for (j = 2; j <= len; j++)
            for (i = 0; i <= len - j; i++) {
                f[i][j] = f[i][j - 1] + f[i + 1][j - 1] - f[i + 1][j - 2];
                if (str[i] == str[i + j - 1]) f[i][j] += f[i + 1][j - 2] + 1;
                f[i][j] = (f[i][j] + MOD) % MOD;
            }
        cout << "Case #" << k << ": ";
        cout << f[0][len] << endl;
    }
    return 0;
}
