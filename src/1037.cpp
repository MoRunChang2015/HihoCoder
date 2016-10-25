#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int a[105][105], f[105][105];
    memset(f, sizeof f, 0);
    int i, j, n;
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++) cin >> a[i][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
    int ans = 0;
    for (i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}
