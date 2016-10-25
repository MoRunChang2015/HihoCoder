#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int map[1003][1003];
int dct[1003];
bool f[1003];
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) cin >> map[i][j];
    for (i = 1; i <= n; i++) dct[i] = map[1][i], f[i] = 1;
    f[1] = 0;
    m = 1;
    int ans = 0;
    while (m < n) {
        int min = -1;
        int p = -1;
        for (i = 1; i <= n; i++)
            if (f[i] == 1)
                if (min == -1)
                    min = dct[i], p = i;
                else if (min > dct[i])
                    min = dct[i], p = i;
        if (p == -1) break;
        ans += dct[p];
        f[p] = 0;
        m++;
        for (i = 1; i <= n; i++)
            if (f[i] == 1) dct[i] = dct[i] > map[p][i] ? map[p][i] : dct[i];
    }
    cout << ans << endl;
    return 0;
}
